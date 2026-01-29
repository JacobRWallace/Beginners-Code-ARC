#!/usr/bin/env python3
"""
Search Visualizer (Tkinter)
- BFS, DFS, Best-First, UCS, Greedy Best-First, A*
- Same tree in each panel
- Universal Play/Pause + Restart + Timeline + Speed + Loop
- Smooth tween between steps
- Collision-avoiding node/edge labels
- Built-in Dark/Light theme toggle (instant)
- DEFAULT: Light theme
- NO external theme files (no style.json, style_light.json)
- Canvas auto-fits entire graph + cursor ring (no clipping)
"""

import math
import tkinter as tk
from tkinter import ttk
import heapq
from dataclasses import dataclass
from typing import Dict, List, Tuple, Optional, Set

# =========================
# Tree (same for all)
# =========================
TREE: Dict[str, List[Tuple[str, int]]] = {
    "S": [("A", 2), ("B", 1), ("C", 4)],
    "A": [("D", 5), ("E", 1)],
    "B": [("F", 2), ("G", 9)],   # goal is "G"
    "C": [("H", 2), ("I", 3)],
    "D": [("J", 3)],
    "E": [("K", 6), ("L", 2)],
    "F": [("M", 4)],
    "H": [("N", 2)],
    "I": [("O", 1)],
}

START = "S"
GOAL = "G"

H: Dict[str, int] = {
    "S": 6, "A": 5, "B": 2, "C": 7,
    "D": 8, "E": 4, "F": 3, "G": 0,
    "H": 6, "I": 5, "J": 9, "K": 6, "L": 4,
    "M": 4, "N": 7, "O": 4
}

# Normalized layout positions (0..1). We'll auto-fit these into the canvas with safe padding.
POS: Dict[str, Tuple[float, float]] = {
    "S": (0.50, 0.08),

    "A": (0.23, 0.22),
    "B": (0.50, 0.22),
    "C": (0.77, 0.22),

    "D": (0.14, 0.38),
    "E": (0.30, 0.38),

    "F": (0.43, 0.38),
    "G": (0.57, 0.38),

    "H": (0.70, 0.38),
    "I": (0.84, 0.38),

    "J": (0.10, 0.56),
    "K": (0.26, 0.56),
    "L": (0.34, 0.56),

    "M": (0.43, 0.56),

    "N": (0.70, 0.56),
    "O": (0.84, 0.56),
}

PARENT: Dict[str, str] = {}
for p, kids in TREE.items():
    for c, _w in kids:
        PARENT[c] = p

# =========================
# Themes (Dark + Light)
# =========================
DARK_STYLE = {
    "window": {"title": "Search Visualizer - Dark UI", "min_width": 1200, "min_height": 750},
    "ttk": {
        "theme": "clam",
        "font_family": "Segoe UI",
        "font_size": 10,
        "bg": "#0b0d10",
        "fg": "#e8e8e8",
        "muted": "#9aa6b2",
        "card_bg": "#12161c",
        "card_border": "#2a2f38",
        "accent": "#b280ff"
    },
    "canvas": {
        "bg": "#161a20",
        "border": "#2a2f38",
        "node_radius": 15,
        "edge_width": 1,
        "edge_active_width": 4,
        "node_fill": "#ffffff",
        "node_outline": "#000000",
        "node_explored": "#cfe8ff",
        "node_current": "#b280ff",
        "node_goal": "#dfffdc",
        "text_secondary": "#9aa6b2",
        "edge_text": "#e8e8e8"
    },
    "animation": {"fps": 30, "ms_per_step": 650, "tween_ease": "smoothstep"}
}

LIGHT_STYLE = {
    "window": {"title": "Search Visualizer - Light UI", "min_width": 1200, "min_height": 750},
    "ttk": {
        "theme": "clam",
        "font_family": "Segoe UI",
        "font_size": 10,
        "bg": "#f5f6f8",
        "fg": "#111318",
        "muted": "#556070",
        "card_bg": "#ffffff",
        "card_border": "#d6dae1",
        "accent": "#2563eb"
    },
    "canvas": {
        "bg": "#ffffff",
        "border": "#d6dae1",
        "node_radius": 15,
        "edge_width": 1,
        "edge_active_width": 4,
        "node_fill": "#ffffff",
        "node_outline": "#111318",
        "node_explored": "#dbeafe",
        "node_current": "#2563eb",
        "node_goal": "#dcfce7",
        "text_secondary": "#556070",
        "edge_text": "#111318"
    },
    "animation": {"fps": 30, "ms_per_step": 650, "tween_ease": "smoothstep"}
}

def build_theme(kind: str) -> dict:
    return LIGHT_STYLE if kind == "light" else DARK_STYLE

# =========================
# Algorithms -> expansion list
# =========================
def bfs_order() -> List[Tuple[str, Optional[str]]]:
    q = [START]
    seen: Set[str] = {START}
    events: List[Tuple[str, Optional[str]]] = []
    while q:
        n = q.pop(0)
        events.append((n, PARENT.get(n)))
        if n == GOAL:
            break
        for child, _ in TREE.get(n, []):
            if child not in seen:
                seen.add(child)
                q.append(child)
    return events

def dfs_order() -> List[Tuple[str, Optional[str]]]:
    stack = [START]
    seen: Set[str] = set()
    events: List[Tuple[str, Optional[str]]] = []
    while stack:
        n = stack.pop()
        if n in seen:
            continue
        seen.add(n)
        events.append((n, PARENT.get(n)))
        if n == GOAL:
            break
        for child, _ in reversed(TREE.get(n, [])):
            if child not in seen:
                stack.append(child)
    return events

def best_first_order() -> List[Tuple[str, Optional[str]]]:
    pq = [(H.get(START, 10**9), START)]
    seen: Set[str] = set()
    events: List[Tuple[str, Optional[str]]] = []
    while pq:
        _, n = heapq.heappop(pq)
        if n in seen:
            continue
        seen.add(n)
        events.append((n, PARENT.get(n)))
        if n == GOAL:
            break
        for child, _ in TREE.get(n, []):
            if child not in seen:
                heapq.heappush(pq, (H.get(child, 10**9), child))
    return events

def ucs_order() -> List[Tuple[str, Optional[str]]]:
    pq = [(0, START)]
    best_g = {START: 0}
    closed: Set[str] = set()
    events: List[Tuple[str, Optional[str]]] = []
    while pq:
        g, n = heapq.heappop(pq)
        if n in closed:
            continue
        closed.add(n)
        events.append((n, PARENT.get(n)))
        if n == GOAL:
            break
        for child, w in TREE.get(n, []):
            ng = g + w
            if child not in closed and (child not in best_g or ng < best_g[child]):
                best_g[child] = ng
                heapq.heappush(pq, (ng, child))
    return events

def greedy_best_first_order() -> List[Tuple[str, Optional[str]]]:
    return best_first_order()

def astar_order() -> List[Tuple[str, Optional[str]]]:
    pq = [(H.get(START, 10**9), 0, START)]
    best_g = {START: 0}
    closed: Set[str] = set()
    events: List[Tuple[str, Optional[str]]] = []
    while pq:
        _, g, n = heapq.heappop(pq)
        if n in closed:
            continue
        closed.add(n)
        events.append((n, PARENT.get(n)))
        if n == GOAL:
            break
        for child, w in TREE.get(n, []):
            ng = g + w
            if child in closed:
                continue
            if child not in best_g or ng < best_g[child]:
                best_g[child] = ng
                heapq.heappush(pq, (ng + H.get(child, 10**9), ng, child))
    return events

ALGO_SPECS = [
    ("BFS", bfs_order, "Layer by layer (shallow → deeper)."),
    ("DFS", dfs_order, "One branch deep, then backtrack."),
    ("Best-First", best_first_order, "Lowest h(n) next (goal-looking)."),
    ("UCS", ucs_order, "Lowest g(n) next (cheapest so far)."),
    ("Greedy", greedy_best_first_order, "Heuristic-only h(n), ignores cost."),
    ("A*", astar_order, "Lowest f(n)=g(n)+h(n) next."),
]

# =========================
# Helpers
# =========================
def clamp(v, lo, hi):
    return lo if v < lo else hi if v > hi else v

def rects_intersect(a, b) -> bool:
    ax1, ay1, ax2, ay2 = a
    bx1, by1, bx2, by2 = b
    return not (ax2 < bx1 or bx2 < ax1 or ay2 < by1 or by2 < ay1)

def smoothstep(t: float) -> float:
    t = clamp(t, 0.0, 1.0)
    return t * t * (3 - 2 * t)

def ease(name: str, t: float) -> float:
    if name == "linear":
        return clamp(t, 0.0, 1.0)
    return smoothstep(t)

def place_text_no_overlap(canvas: tk.Canvas,
                          x: float, y: float,
                          text: str,
                          font,
                          fill: str,
                          placed: List[Tuple[int, int, int, int]],
                          extra_avoid: List[Tuple[int, int, int, int]] = None,
                          pad: int = 2,
                          offsets: List[Tuple[int, int]] = None):
    """
    Try multiple offsets to place text without overlapping 'placed' or 'extra_avoid'.
    Returns (text_id, bbox) or (None, None).
    """
    if extra_avoid is None:
        extra_avoid = []
    if offsets is None:
        offsets = [(0, 0)]

    for ox, oy in offsets:
        tid = canvas.create_text(x + ox, y + oy, text=text, font=font, fill=fill)
        bbox = canvas.bbox(tid)
        if not bbox:
            canvas.delete(tid)
            continue

        bb = (bbox[0] - pad, bbox[1] - pad, bbox[2] + pad, bbox[3] + pad)

        blocked = False
        for r in placed:
            if rects_intersect(bb, r):
                blocked = True
                break
        if not blocked:
            for r in extra_avoid:
                if rects_intersect(bb, r):
                    blocked = True
                    break

        if blocked:
            canvas.delete(tid)
            continue

        placed.append(bb)
        return tid, bb

    return None, None

@dataclass
class PanelState:
    events: List[Tuple[str, Optional[str]]]
    title: str
    note: str

class AlgoPanel(ttk.Frame):
    def __init__(self, master, state: PanelState, S: dict):
        super().__init__(master, style="Card.TFrame")
        self.state = state
        self.S = S

        ff = S["ttk"]["font_family"]

        self.title_lbl = ttk.Label(self, text=state.title, anchor="w",
                                   font=(ff, 10, "bold"), style="Card.TLabel")
        self.title_lbl.pack(fill="x", padx=10, pady=(10, 4))

        # Give a more generous starting height; it still resizes with the grid.
        self.canvas = tk.Canvas(self, height=300, bg=S["canvas"]["bg"], highlightthickness=1)
        self.canvas.pack(fill="both", expand=True, padx=10)

        self.note_lbl = ttk.Label(self, text=state.note, anchor="w",
                                  font=(ff, 9), style="CardMuted.TLabel")
        self.note_lbl.pack(fill="x", padx=10, pady=(6, 10))

        self.canvas.bind("<Configure>", lambda _e: self.render(0, 0.0))

        # Cache POS bounds for fitting
        xs = [p[0] for p in POS.values()]
        ys = [p[1] for p in POS.values()]
        self.pos_minx, self.pos_maxx = min(xs), max(xs)
        self.pos_miny, self.pos_maxy = min(ys), max(ys)

    def apply_theme(self, S: dict):
        self.S = S
        self.canvas.configure(bg=S["canvas"]["bg"], highlightbackground=S["canvas"]["border"])

        # Force-refresh label colors (fixes dark-mode note text disappearing on some systems)
        card_bg = S["ttk"]["card_bg"]
        fg = S["ttk"]["fg"]
        muted = S["ttk"]["muted"]

        self.title_lbl.configure(background=card_bg, foreground=fg)
        self.note_lbl.configure(background=card_bg, foreground=muted)

    def _map_pos(self, nx: float, ny: float, w: int, h: int) -> Tuple[float, float]:
        """
        Map normalized node positions into the canvas with safe padding so
        nodes + cursor ring never clip.
        """
        r = self.S["canvas"]["node_radius"]
        cursor_pad = (r + 8) + 6  # ring radius + line thickness safety
        label_pad = 22            # room for h= labels / edge text
        pad = int(max(cursor_pad, r) + label_pad)

        left, top = pad, pad
        right, bottom = w - pad, h - pad

        # Avoid degenerate scaling when panel becomes tiny
        right = max(right, left + 10)
        bottom = max(bottom, top + 10)

        spanx = max(1e-9, (self.pos_maxx - self.pos_minx))
        spany = max(1e-9, (self.pos_maxy - self.pos_miny))

        tx = (nx - self.pos_minx) / spanx
        ty = (ny - self.pos_miny) / spany

        X = left + tx * (right - left)
        Y = top + ty * (bottom - top)
        return X, Y

    def render(self, step: int, tween: float):
        self.canvas.delete("all")

        w = max(1, self.canvas.winfo_width())
        h = max(1, self.canvas.winfo_height())
        self.canvas.config(highlightbackground=self.S["canvas"]["border"])

        if not self.state.events:
            return

        max_local = len(self.state.events) - 1
        step = clamp(step, 0, max_local)
        next_step = clamp(step + 1, 0, max_local)

        expanded = [n for (n, _) in self.state.events[:step + 1]]
        expanded_set = set(expanded)
        current = expanded[-1] if expanded else None
        next_node = self.state.events[next_step][0] if next_step != step else current

        # animated cursor
        cursor_x = cursor_y = 0
        if current and next_node:
            x1, y1 = POS[current]
            x2, y2 = POS[next_node]
            et = ease(self.S["animation"]["tween_ease"], tween)
            cx = (x1 + (x2 - x1) * et)
            cy = (y1 + (y2 - y1) * et)
            cursor_x, cursor_y = self._map_pos(cx, cy, w, h)

        placed = []

        # edges + cost labels
        for parent, kids in TREE.items():
            for child, cost in kids:
                X1, Y1 = self._map_pos(POS[parent][0], POS[parent][1], w, h)
                X2, Y2 = self._map_pos(POS[child][0], POS[child][1], w, h)

                active = (child in expanded_set and PARENT.get(child) == parent)
                width = self.S["canvas"]["edge_active_width"] if active else self.S["canvas"]["edge_width"]
                self.canvas.create_line(X1, Y1, X2, Y2, width=width)

                mx, my = (X1 + X2) / 2, (Y1 + Y2) / 2
                dx, dy = (X2 - X1), (Y2 - Y1)
                length = max(1.0, math.hypot(dx, dy))
                px, py = (-dy / length, dx / length)

                candidates = []
                base = 14
                offsets = []
                for mult in (1, -1, 2, -2, 3, -3):
                    offsets.append((px * base * mult, py * base * mult))

                # If those fail, try a small vertical "ladder"
                for dy2 in (-18, -30, -42, 18, 30, 42):
                    offsets.append((0, dy2))

                place_text_no_overlap(
                    self.canvas,
                    mx, my,
                    text=str(cost),
                    font=(self.S["ttk"]["font_family"], 8),
                    fill=self.S["canvas"]["edge_text"],
                    placed=placed,
                    offsets=[(int(ox), int(oy)) for (ox, oy) in offsets],
                    pad=2
                )

        # nodes + h labels
        r = self.S["canvas"]["node_radius"]
        for node, (nx, ny) in POS.items():
            X, Y = self._map_pos(nx, ny, w, h)

            fill = self.S["canvas"]["node_fill"]
            if node == GOAL:
                fill = self.S["canvas"]["node_goal"]
            if node in expanded_set:
                fill = self.S["canvas"]["node_explored"]
            if node == current:
                fill = self.S["canvas"]["node_current"]

            self.canvas.create_oval(
                X - r, Y - r, X + r, Y + r,
                fill=fill, outline=self.S["canvas"]["node_outline"], width=2
            )
            self.canvas.create_text(X, Y, text=node,
                                    font=(self.S["ttk"]["font_family"], 9, "bold"),
                                    fill=self.S["ttk"]["fg"])

            if node in H:
                text = f"h={H[node]}"
                font = (self.S["ttk"]["font_family"], 8)
                color = self.S["canvas"]["text_secondary"]

                node_rect = (X - r - 2, Y - r - 2, X + r + 2, Y + r + 2)

                # Try “nice” spots first, then fan out downward so close siblings (K/L) don't overlap.
                primary = [
                    (r + 18, 0), (-(r + 18), 0),
                    (0, r + 18), (0, -(r + 18)),
                    (r + 18, r + 14), (-(r + 18), r + 14),
                ]

                # Add a downward ladder + a slight left/right wobble to break ties
                ladder = []
                for k in range(1, 10):
                    ladder.append((0, r + 14 + 12 * k))
                    ladder.append((10, r + 14 + 12 * k))
                    ladder.append((-10, r + 14 + 12 * k))

                offsets = primary + ladder

                place_text_no_overlap(
                    self.canvas,
                    X, Y,
                    text=text,
                    font=font,
                    fill=color,
                    placed=placed,
                    extra_avoid=[node_rect],
                    offsets=[(int(ox), int(oy)) for (ox, oy) in offsets],
                    pad=2
                )

        # cursor ring
        cr = r + 8
        self.canvas.create_oval(cursor_x - cr, cursor_y - cr, cursor_x + cr, cursor_y + cr,
                                outline=self.S["ttk"]["accent"], width=3)

class App(tk.Tk):
    def __init__(self):
        super().__init__()

        # DEFAULT: LIGHT THEME
        self.theme_kind = "light"
        self.S = build_theme(self.theme_kind)

        self._build_ui()

    def _build_ui(self):
        self.title(self.S["window"]["title"])
        self.minsize(self.S["window"]["min_width"], self.S["window"]["min_height"])
        self.configure(bg=self.S["ttk"]["bg"])

        self._setup_ttk()

        # sequences
        states: List[PanelState] = []
        max_len = 0
        for name, fn, note in ALGO_SPECS:
            events = fn()
            states.append(PanelState(events=events, title=name, note=note))
            max_len = max(max_len, len(events))
        self.max_step = max(1, max_len) - 1

        # playback
        self.is_playing = False
        self.loop_enabled = tk.BooleanVar(value=True)
        self.speed_var = tk.DoubleVar(value=1.0)

        self.fps = max(10, int(self.S["animation"]["fps"]))
        self.base_ms_per_step = max(150, int(self.S["animation"]["ms_per_step"]))
        self.ms_per_frame = int(1000 / self.fps)

        self.step = 0
        self.tween = 0.0
        self.after_id = None

        # top controls
        top = ttk.Frame(self, style="Top.TFrame")
        top.pack(fill="x", padx=12, pady=12)

        self.play_btn = ttk.Button(top, text="Play", command=self.toggle_play, style="Accent.TButton")
        self.play_btn.pack(side="left")

        ttk.Button(top, text="Restart", command=self.restart).pack(side="left", padx=(8, 0))

        ttk.Checkbutton(top, text="Loop", variable=self.loop_enabled).pack(side="left", padx=(12, 0))

        ttk.Label(top, text="Timeline").pack(side="left", padx=(18, 6))
        self.timeline = ttk.Scale(top, from_=0, to=self.max_step, orient="horizontal", command=self.on_timeline)
        self.timeline.pack(side="left", fill="x", expand=True, padx=(0, 10))

        self.step_lbl = ttk.Label(top, text=f"{self.step}/{self.max_step}")
        self.step_lbl.pack(side="left", padx=(0, 14))

        ttk.Label(top, text="Speed").pack(side="left", padx=(0, 6))
        self.speed = ttk.Scale(top, from_=0.25, to=3.0, orient="horizontal", command=self.on_speed)
        self.speed.set(1.0)
        self.speed.pack(side="left", padx=(0, 8), ipadx=30)

        self.speed_lbl = ttk.Label(top, text="1.00×")
        self.speed_lbl.pack(side="left")

        # theme toggle
        self.theme_btn = ttk.Button(top, text="Dark Mode", command=self.toggle_theme)
        self.theme_btn.pack(side="left", padx=(14, 0))

        # grid
        grid = ttk.Frame(self, style="Grid.TFrame")
        grid.pack(fill="both", expand=True, padx=12, pady=(0, 12))

        self.panels: List[AlgoPanel] = []
        for i, st in enumerate(states):
            p = AlgoPanel(grid, st, self.S)
            self.panels.append(p)
            r = i // 3
            c = i % 3
            p.grid(row=r, column=c, sticky="nsew", padx=8, pady=8)

        for c in range(3):
            grid.columnconfigure(c, weight=1)
        for r in range(2):
            grid.rowconfigure(r, weight=1)

        self.render_all()

    def _setup_ttk(self):
        S = self.S
        style = ttk.Style()
        theme = S["ttk"]["theme"]
        try:
            if theme in style.theme_names():
                style.theme_use(theme)
        except Exception:
            pass

        ff = S["ttk"]["font_family"]
        fs = S["ttk"]["font_size"]
        bg = S["ttk"]["bg"]
        fg = S["ttk"]["fg"]
        muted = S["ttk"]["muted"]
        card_bg = S["ttk"]["card_bg"]
        accent = S["ttk"]["accent"]

        self.configure(bg=bg)

        style.configure(".", font=(ff, fs), foreground=fg)
        style.configure("Top.TFrame", background=bg)
        style.configure("Grid.TFrame", background=bg)

        style.configure("TLabel", background=bg, foreground=fg)
        style.configure("TCheckbutton", background=bg, foreground=fg)

        style.configure("Card.TFrame", background=card_bg, borderwidth=1, relief="solid")
        style.configure("Card.TLabel", background=card_bg, foreground=fg)
        style.configure("CardMuted.TLabel", background=card_bg, foreground=muted)

        style.configure("TButton", padding=(10, 7))
        style.configure("Accent.TButton", padding=(10, 7))
        style.map("Accent.TButton",
                  background=[("active", accent)],
                  foreground=[("active", S["ttk"]["bg"])])

        style.configure("TScale", background=bg)

    def toggle_theme(self):
        self.theme_kind = "dark" if self.theme_kind == "light" else "light"
        self.S = build_theme(self.theme_kind)

        self._setup_ttk()
        self.title(self.S["window"]["title"])
        self.theme_btn.config(text="Dark Mode" if self.theme_kind == "light" else "Light Mode")

        for p in self.panels:
            p.apply_theme(self.S)

        self.fps = max(10, int(self.S["animation"]["fps"]))
        self.base_ms_per_step = max(150, int(self.S["animation"]["ms_per_step"]))
        self.ms_per_frame = int(1000 / self.fps)

        self.render_all()

    def on_speed(self, _val):
        v = float(self.speed.get())
        self.speed_var.set(v)
        self.speed_lbl.config(text=f"{v:.2f}×")

    def on_timeline(self, _val):
        s = int(float(self.timeline.get()) + 0.5)
        s = clamp(s, 0, self.max_step)
        self.step = s
        self.tween = 0.0
        self.render_all()

    def restart(self):
        self.step = 0
        self.tween = 0.0
        self.timeline.set(0)
        self.render_all()

    def render_all(self):
        self.step_lbl.config(text=f"{self.step}/{self.max_step}")
        for p in self.panels:
            p.render(self.step, self.tween)

    def toggle_play(self):
        self.is_playing = not self.is_playing
        self.play_btn.config(text="Pause" if self.is_playing else "Play")
        if self.is_playing:
            self._tick()
        else:
            if self.after_id is not None:
                self.after_cancel(self.after_id)
                self.after_id = None

    def _tick(self):
        if not self.is_playing:
            return

        speed = max(0.25, float(self.speed_var.get()))
        ms_per_step = self.base_ms_per_step / speed

        self.tween += self.ms_per_frame / ms_per_step

        if self.tween >= 1.0:
            self.tween -= 1.0
            self.step += 1

            if self.step > self.max_step:
                if self.loop_enabled.get():
                    self.step = 0
                else:
                    self.step = self.max_step
                    self.is_playing = False
                    self.play_btn.config(text="Play")

            self.timeline.set(self.step)

        self.render_all()
        self.after_id = self.after(self.ms_per_frame, self._tick)

if __name__ == "__main__":
    App().mainloop()
