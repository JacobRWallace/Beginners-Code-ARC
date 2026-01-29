"""
animated_time_complexity.py

Animated visualization of a simple algorithm's time steps.

Left:  graph of "operations so far" vs step (simulating work)
Right: pseudo-code with the currently executing line highlighted.

Every second, we advance one "step" in the simulated execution trace.
"""

import matplotlib.pyplot as plt
import matplotlib.animation as animation

# ---------------------------------------------------------
# 1. Define the pseudo-code and an execution trace
# ---------------------------------------------------------

# Pseudo-code lines (1-based indexing for readability)
PSEUDOCODE = [
    "1: total = 0",
    "2: for i in range(n):",
    "3:     total += i",
    "4: return total",
]

# Simulate running this for n iterations
N = 10

# Build an execution trace: each entry = line number executed at that step
execution_trace = []

# Step for initialization
execution_trace.append(1)  # total = 0

# Loop simulation
# We'll pretend that each iteration does:
#   - check/update loop line (2)
#   - run body (3)
for i in range(N):
    execution_trace.append(2)  # for i in range(n):
    execution_trace.append(3)  # total += i

# After loop ends, "return"
execution_trace.append(4)  # return total

TOTAL_STEPS = len(execution_trace)

# ---------------------------------------------------------
# 2. Set up matplotlib figure: left = graph, right = code
# ---------------------------------------------------------

fig = plt.figure(figsize=(10, 6))

# Left axis = line graph
ax_graph = fig.add_subplot(1, 2, 1)
ax_graph.set_title("Operations vs. Step")
ax_graph.set_xlabel("Step")
ax_graph.set_ylabel("Cumulative Operations")

# Right axis = pseudo-code
ax_code = fig.add_subplot(1, 2, 2)
ax_code.axis("off")
ax_code.set_title("Pseudo-code Execution")

# Data for the line plot
x_data = []
y_data = []
line_plot, = ax_graph.plot([], [], marker="o")

# We'll also keep a text annotation showing current step/op count
step_text = ax_graph.text(0.05, 0.9, "", transform=ax_graph.transAxes)

# ---------------------------------------------------------
# 3. Helper to draw pseudo-code with highlight
# ---------------------------------------------------------

def draw_code(current_line):
    """
    Draw the pseudo-code on the right axis,
    highlighting the current_line (1-based index).
    """
    ax_code.clear()
    ax_code.axis("off")
    ax_code.set_title("Pseudo-code Execution")

    # vertical placement from top down
    y_start = 0.9
    y_step = 0.15

    for idx, line in enumerate(PSEUDOCODE, start=1):
        y = y_start - (idx - 1) * y_step

        if idx == current_line:
            # Highlight current line
            ax_code.text(
                0.0, y, line,
                transform=ax_code.transAxes,
                fontsize=12,
                fontweight="bold",
                color="red",
            )
        else:
            ax_code.text(
                0.0, y, line,
                transform=ax_code.transAxes,
                fontsize=11,
                color="black",
            )

# ---------------------------------------------------------
# 4. Animation update function
# ---------------------------------------------------------

def init():
    # Initial setup for the graph
    ax_graph.set_xlim(0, TOTAL_STEPS)
    ax_graph.set_ylim(0, TOTAL_STEPS + 1)
    line_plot.set_data([], [])
    step_text.set_text("")
    draw_code(current_line=1)
    return line_plot, step_text

def update(frame):
    """
    frame: which step we are on (0-based)
    """
    step_number = frame + 1  # 1-based step count
    current_line = execution_trace[frame]

    # Update data for the line plot
    x_data.append(step_number)
    # We simulate "1 operation per step" here; you could make this more detailed.
    y_data.append(step_number)

    line_plot.set_data(x_data, y_data)

    # Adjust axes if needed (optional since we set fixed limits)
    ax_graph.set_xlim(0, TOTAL_STEPS + 1)
    ax_graph.set_ylim(0, TOTAL_STEPS + 2)

    # Update step text
    step_text.set_text(f"Step: {step_number}\nLine: {current_line}")

    # Redraw pseudo-code with highlight on the current line
    draw_code(current_line=current_line)

    return line_plot, step_text

# ---------------------------------------------------------
# 5. Run animation
# ---------------------------------------------------------

ani = animation.FuncAnimation(
    fig,
    update,
    frames=TOTAL_STEPS,
    init_func=init,
    interval=1000,   # 1000 ms = 1 second per step
    blit=False,
    repeat=False
)

plt.tight_layout()
plt.show()
