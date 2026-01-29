#!/usr/bin/env python3
"""
Educational example: scrape PUBLIC Instagram posts only, without login.

Given one or more post URLs, this script:
  - downloads the post's public HTML
  - tries to parse rich JSON in this order:
        1) __NEXT_DATA__ (if available without login)
        2) <script type="application/ld+json"> SEO blob
  - extracts:
        - author username / name
        - caption text
        - (when available) tagged users + audio/song info
        - all image URLs (single or multi-image)
  - saves into ig_public_downloads/<date__shortcode>/ as:
        - meta.json
        - caption.txt
        - media_01.jpg, media_02.jpg, ...

No cookies, no account access, only what Instagram serves to a logged-out browser.
"""

import os
import re
import json
import time
from pathlib import Path
from urllib.parse import urlparse
from typing import Any, Dict, List, Optional

import requests


class PublicInstagramScraper:
    def __init__(self, out_dir: str = "ig_public_downloads"):
        self.session = requests.Session()
        self.session.headers.update({
            "User-Agent": (
                "Mozilla/5.0 (Windows NT 10.0; Win64; x64) "
                "AppleWebKit/537.36 (KHTML, like Gecko) "
                "Chrome/120.0 Safari/537.36"
            )
        })
        self.out_dir = Path(out_dir)
        self.out_dir.mkdir(exist_ok=True)

    # ---------------------- public API ----------------------

    def scrape_posts(self, urls: List[str]) -> None:
        for url in urls:
            print(f"\n=== Scraping PUBLIC post: {url} ===")
            try:
                post_data = self.fetch_post(url)
                self.save_post(post_data)
            except Exception as e:
                print(f"[ERROR] Failed for {url}: {e}")

    # ------------------ fetching & parsing -------------------

    def fetch_post(self, url: str) -> Dict[str, Any]:
        """Fetch HTML for a public post and parse its main media object."""
        parsed = urlparse(url)
        clean_url = f"{parsed.scheme}://{parsed.netloc}{parsed.path}"
        if not clean_url.endswith("/"):
            clean_url += "/"

        resp = self.session.get(clean_url)
        resp.raise_for_status()

        html = resp.text

        # Try flexible __NEXT_DATA__ first
        media = None
        shortcode = self._extract_shortcode_from_path(parsed.path)

        m = re.search(
            r'<script[^>]+id=["\']__NEXT_DATA__["\'][^>]*>(.*?)</script>',
            html,
            re.DOTALL,
        )

        if m:
            try:
                next_data = json.loads(m.group(1))
                page_props = next_data.get("props", {}).get("pageProps", {})
                media = (
                    page_props.get("media")
                    or page_props.get("post")
                    or page_props.get("item")
                    or page_props.get("graphql", {}).get("shortcode_media")
                )
                if media:
                    parsed_media = self._parse_media_next_data(media, shortcode)
                    return parsed_media
            except Exception as e:
                print(f"[WARN] Failed parsing __NEXT_DATA__: {e}")

        # Fallback: SEO ld+json block (works on most public posts)
        ld = self._extract_ld_json(html)
        if ld:
            parsed_media = self._parse_media_ld(ld, shortcode)
            return parsed_media

        # If we get here, there's really nothing public to parse
        raise RuntimeError(
            "Could not find usable JSON (no __NEXT_DATA__ or ld+json). "
            "The post may require login or the layout changed again."
        )

    def _extract_shortcode_from_path(self, path: str) -> Optional[str]:
        """
        /p/DTi7dYXk-79/ -> DTi7dYXk-79
        /reel/XXXXXXXX/ -> XXXXXXXX
        """
        parts = [p for p in path.split("/") if p]
        if len(parts) >= 2:
            return parts[1]
        return None

    def _extract_ld_json(self, html: str) -> Optional[Dict[str, Any]]:
        """
        Grab the <script type="application/ld+json"> JSON blob.

        Instagram often wraps it like:
            <script type="application/ld+json">{ ... }</script>

        Sometimes it's a list; sometimes a single object.
        """
        m = re.search(
            r'<script type="application/ld\+json">(.*?)</script>',
            html,
            re.DOTALL,
        )
        if not m:
            return None

        try:
            raw = m.group(1).strip()
            data = json.loads(raw)
            # Sometimes it's [obj], sometimes obj
            if isinstance(data, list) and data:
                return data[0]
            if isinstance(data, dict):
                return data
        except Exception as e:
            print(f"[WARN] Failed to parse ld+json: {e}")
        return None

    def _parse_media_next_data(self, media: Dict[str, Any], shortcode: Optional[str]) -> Dict[str, Any]:
        """Parse from the richer __NEXT_DATA__ structure (if available)."""

        ts = media.get("taken_at_timestamp") or media.get("taken_at") or int(time.time())
        caption_text = ""
        edges = media.get("edge_media_to_caption", {}).get("edges", [])
        if edges:
            caption_text = edges[0].get("node", {}).get("text", "") or caption_text
        if not caption_text:
            caption_text = (media.get("caption") or {}).get("text", "") or caption_text

        owner = media.get("owner") or media.get("user") or {}
        author_username = owner.get("username")
        author_full_name = owner.get("full_name") or owner.get("name")

        tagged_users: List[str] = []
        usertags = media.get("edge_media_to_tagged_user") or media.get("usertags") or {}
        if "edges" in usertags:
            for e in usertags.get("edges", []):
                u = e.get("node", {}).get("user", {}).get("username")
                if u:
                    tagged_users.append(u)
        else:
            for t in usertags.get("in", []):
                u = t.get("user", {}).get("username")
                if u:
                    tagged_users.append(u)

        # Audio / song info for reels (if available publicly)
        audio_info: Optional[Dict[str, Any]] = None
        clips_meta = media.get("clips_metadata") or {}
        music_info = clips_meta.get("music_info") or {}
        asset = music_info.get("music_asset_info") or {}
        if asset:
            audio_info = {
                "title": asset.get("title") or asset.get("display_name"),
                "artist": asset.get("display_artist"),
                "id": asset.get("id"),
            }

        media_urls: List[str] = []
        typename = media.get("__typename") or media.get("media_type")

        if typename in ("GraphSidecar", "GraphCarousel", 8):
            children = (
                media.get("edge_sidecar_to_children", {}).get("edges")
                or media.get("carousel_media")
                or []
            )
            for edge in children:
                node = edge.get("node", edge)
                url = (
                    node.get("display_url")
                    or node.get("thumbnail_src")
                    or node.get("image_versions2", {}).get("candidates", [{}])[0].get("url")
                )
                if url:
                    media_urls.append(url)
        else:
            url = (
                media.get("display_url")
                or media.get("thumbnail_src")
                or media.get("image_versions2", {}).get("candidates", [{}])[0].get("url")
            )
            if url:
                media_urls.append(url)

        return {
            "shortcode": shortcode or media.get("shortcode") or media.get("id"),
            "timestamp": ts,
            "author": {
                "username": author_username,
                "full_name": author_full_name,
            },
            "caption": caption_text,
            "tagged_users": tagged_users,
            "audio": audio_info,
            "media_urls": media_urls,
            "source": "next_data",
            "raw": media,
        }

    def _parse_media_ld(self, ld: Dict[str, Any], shortcode: Optional[str]) -> Dict[str, Any]:
        """
        Parse from the SEO ld+json blob.

        This is lighter: usually only author, caption/description,
        uploadDate, and image(s). Song + tags usually aren't exposed here.
        """

        # Caption / description
        caption = (
            ld.get("caption")
            or ld.get("description")
            or ld.get("articleBody")
            or ""
        )

        # Author info
        author_username = None
        author_full_name = None
        author = ld.get("author")
        if isinstance(author, dict):
            author_full_name = author.get("name")
            # Some posts use alternateName as @handle
            author_username = author.get("alternateName") or author_full_name

        # Timestamp
        upload_date = ld.get("uploadDate") or ld.get("datePublished")
        # Just store raw string; also keep a numeric timestamp for folder naming
        if upload_date:
            try:
                # Rough parse: YYYY-MM-DD...
                ts_struct = time.strptime(upload_date[:10], "%Y-%m-%d")
                ts_numeric = int(time.mktime(ts_struct))
            except Exception:
                ts_numeric = int(time.time())
        else:
            ts_numeric = int(time.time())

        # Images: may be a string or list
        images = ld.get("image")
        media_urls: List[str] = []
        if isinstance(images, list):
            media_urls.extend(images)
        elif isinstance(images, str):
            media_urls.append(images)

        return {
            "shortcode": shortcode or ld.get("identifier") or None,
            "timestamp": ts_numeric,
            "author": {
                "username": author_username,
                "full_name": author_full_name,
            },
            "caption": caption,
            "tagged_users": [],   # ld+json doesn't usually expose this
            "audio": None,        # not present in ld+json
            "media_urls": media_urls,
            "source": "ld+json",
            "raw": ld,
        }

    # ------------------------ saving -------------------------

    def save_post(self, post: Dict[str, Any]) -> None:
        shortcode = post.get("shortcode") or str(post.get("timestamp"))
        ts = time.strftime("%Y-%m-%d", time.localtime(post["timestamp"]))

        folder = self.out_dir / f"{ts}__{shortcode}"
        folder.mkdir(exist_ok=True)

        # Save metadata
        with (folder / "meta.json").open("w", encoding="utf-8") as f:
            json.dump(post, f, ensure_ascii=False, indent=2)

        # Save caption alone
        with (folder / "caption.txt").open("w", encoding="utf-8") as f:
            f.write(post.get("caption") or "")

        # Download all media
        for i, url in enumerate(post.get("media_urls", []), start=1):
            print(f"  -> downloading media {i}: {url}")
            self._download_file(url, folder, i)

        print(f"Saved PUBLIC post to: {folder}")

    def _download_file(self, url: str, folder: Path, index: int) -> None:
        resp = self.session.get(url, stream=True)
        resp.raise_for_status()

        path = urlparse(url).path
        ext = os.path.splitext(path)[1] or ".jpg"
        filename = f"media_{index:02d}{ext}"

        with (folder / filename).open("wb") as f:
            for chunk in resp.iter_content(chunk_size=8192):
                if chunk:
                    f.write(chunk)


if __name__ == "__main__":
    scraper = PublicInstagramScraper()

    # Put PUBLIC URLs here
    urls = [
        # your example:
        "https://www.instagram.com/p/DTi7dYXk-79/",
    ]

    scraper.scrape_posts(urls)
