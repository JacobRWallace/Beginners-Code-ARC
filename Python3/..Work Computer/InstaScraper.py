# InstaScraper V.2.5
# By: X-Edition
# UI menu, progress bar, range selection, session handling

import os
import time
import logging
from concurrent.futures import ThreadPoolExecutor
from instaloader import Instaloader, Profile
from datetime import datetime
from PIL import Image
from tqdm import tqdm

# SETTINGS
IMAGE_FORMAT = "jpg"
VIDEO_FORMAT = "mp4"
DOWNLOAD_TYPE = "both"
DOWNLOAD_PROFILE_PICTURE = True
CAPTION_EXPORT = True

# ADVANCED SETTINGS
LOGGING_ENABLED = False
SLEEP_INTERVAL = 5
THREAD_COUNT = 3

# FORMATTING
POSTS_FOLDER_FORMAT = "{username}_Posts"
IMAGE_FILENAME_FORMAT = "image{i}"  # Format for image filenames (no extension included)

if LOGGING_ENABLED:
    logging.basicConfig(
        filename="instascraper_log.txt",
        level=logging.INFO,
        format="%(asctime)s - %(message)s",
        filemode="w",
    )

def log(message):
    print(message)
    if LOGGING_ENABLED:
        logging.info(message)

def convert_image_format(input_path, output_format):
    if not os.path.exists(input_path):
        return
    with Image.open(input_path) as img:
        output_path = input_path.rsplit(".", 1)[0] + f".{output_format}"
        img.save(output_path, format=output_format.upper())
        os.remove(input_path)

def download_post(post, post_id, loader, output_dir):
    post_folder = os.path.join(output_dir, post_id)
    if os.path.exists(post_folder):
        return
    os.makedirs(post_folder, exist_ok=True)
    for i, resource in enumerate(post.get_sidecar_nodes(), start=1):
        if resource.is_video and DOWNLOAD_TYPE in ["videos", "both"]:
            file_path = os.path.join(post_folder, f"{IMAGE_FILENAME_FORMAT.format(i=i)}.{VIDEO_FORMAT}")
            loader.download_pic(file_path, resource.video_url, post.date_utc)
        elif not resource.is_video and DOWNLOAD_TYPE in ["images", "both"]:
            file_path = os.path.join(post_folder, f"{IMAGE_FILENAME_FORMAT.format(i=i)}.{IMAGE_FORMAT}")
            loader.download_pic(file_path, resource.display_url, post.date_utc)
            if IMAGE_FORMAT != "jpg":
                convert_image_format(file_path, IMAGE_FORMAT)
    if CAPTION_EXPORT:
        caption_file = os.path.join(post_folder, "caption.txt")
        with open(caption_file, "w", encoding="utf-8") as f:
            f.write(post.caption or "No caption provided.")

def download_profile_picture(profile, output_dir, loader, username):
    profile_pic_raw = profile.profile_pic_url.split("/")[-1].split("?")[0]
    profile_pic_id = profile_pic_raw.rsplit(".", 1)[0]
    profile_pic_path = os.path.join(output_dir, f"pfp_{username}_{profile_pic_id}.{IMAGE_FORMAT}")
    if os.path.exists(profile_pic_path):
        return
    loader.download_pic(profile_pic_path, profile.profile_pic_url, datetime.now())
    if IMAGE_FORMAT != "jpg":
        convert_image_format(profile_pic_path, IMAGE_FORMAT)
    log(f"Profile picture saved as '{profile_pic_path}'")

def download_posts(username, selection_mode):
    loader = Instaloader()
    use_login = input("Do you want to log in to access private accounts? (y/n): ").strip().lower()
    if use_login == "y":
        ig_username = input("Enter your Instagram username: ").strip()
        ig_password = input("Enter your Instagram password: ").strip()
        loader.login(ig_username, ig_password)
        loader.save_session_to_file()
    else:
        try:
            loader.load_session_from_file(username)
        except Exception:
            pass

    output_dir = POSTS_FOLDER_FORMAT.format(username=username)
    os.makedirs(output_dir, exist_ok=True)

    try:
        log(f"Fetching profile for {username}...")
        profile = Profile.from_username(loader.context, username)
        if DOWNLOAD_PROFILE_PICTURE:
            download_profile_picture(profile, output_dir, loader, username)

        posts = list(profile.get_posts())
        total_posts = len(posts)
        log(f"{username} has {total_posts} posts.")

        selected_posts = []
        if selection_mode == "1":
            count = int(input("How many recent posts do you want to download?: ").strip())
            selected_posts = posts[:count]
        elif selection_mode == "2":
            start = int(input(f"Enter start index (0 = most recent): "))
            end = int(input(f"Enter end index (inclusive): "))
            if start < 0 or end >= total_posts or start > end:
                log("Invalid range. Aborting.")
                return
            selected_posts = posts[start:end + 1]
        elif selection_mode == "3":
            selected_posts = posts
            log(f"Downloading all {total_posts} posts...")
        else:
            log("Invalid selection.")
            return

        with ThreadPoolExecutor(max_workers=THREAD_COUNT) as executor:
            futures = []
            for post in tqdm(selected_posts, desc="Downloading posts"):
                post_id = str(post.mediaid)
                futures.append(executor.submit(download_post, post, post_id, loader, output_dir))
            for f in futures: f.result()

        log(f"\nDownloaded {len(selected_posts)} posts from {username} to '{output_dir}'.")

    except Exception as e:
        if "401" in str(e) and "Please wait" in str(e):
            log("Rate limited by Instagram. Wait 15-30 mins and try again.")
        else:
            log(f"An error occurred: {e}")

if __name__ == "__main__":
    target_username = input("Enter the Instagram username to scrape: ").strip()
    print("\nChoose an option:")
    print("1 - Download most recent posts")
    print("2 - Download posts by range")
    print("3 - Download all posts")
    mode = input("Enter your choice (1/2/3): ").strip()
    download_posts(target_username, mode)