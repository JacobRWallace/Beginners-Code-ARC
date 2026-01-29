"""
time_complexity_visualizer.py

Visualize common time complexities using matplotlib.

Curves shown:
  - O(1)
  - O(log n)
  - O(n)
  - O(n log n)
  - O(n^2)
  - O(n^3)
  - O(2^n)  (limited n range so it doesn't blow up too hard)

Run:
    python time_complexity_visualizer.py
"""

import numpy as np
import matplotlib.pyplot as plt


def main():
    # Domain for most functions
    n = np.linspace(1, 100, 100)  # from 1 to 100

    # Smaller domain for 2^n so it doesn't overflow
    n_exp = np.arange(1, 21)  # 1..20

    # Time complexity "shapes"
    f_const   = np.ones_like(n)
    f_log     = np.log2(n)
    f_linear  = n
    f_nlogn   = n * np.log2(n)
    f_quad    = n**2
    f_cubic   = n**3
    f_exp     = 2**n_exp

    # ---------- Create figure ----------
    plt.figure(figsize=(10, 8))

    # ========== 1) Linear scale ==========
    ax1 = plt.subplot(2, 1, 1)
    ax1.set_title("Time Complexity Growth (Linear Scale)")

    ax1.plot(n, f_const,   label="O(1)")
    ax1.plot(n, f_log,     label="O(log n)")
    ax1.plot(n, f_linear,  label="O(n)")
    ax1.plot(n, f_nlogn,   label="O(n log n)")
    ax1.plot(n, f_quad,    label="O(n²)")
    ax1.plot(n, f_cubic,   label="O(n³)")
    ax1.plot(n_exp, f_exp, label="O(2ⁿ)")

    ax1.set_xlabel("n (input size)")
    ax1.set_ylabel("Steps (arbitrary units)")
    ax1.grid(True, alpha=0.3)
    ax1.legend(loc="upper left")

    # ========== 2) Log scale on Y ==========
    ax2 = plt.subplot(2, 1, 2)
    ax2.set_title("Time Complexity Growth (Logarithmic Y-Scale)")

    ax2.plot(n, f_const,   label="O(1)")
    ax2.plot(n, f_log,     label="O(log n)")
    ax2.plot(n, f_linear,  label="O(n)")
    ax2.plot(n, f_nlogn,   label="O(n log n)")
    ax2.plot(n, f_quad,    label="O(n²)")
    ax2.plot(n, f_cubic,   label="O(n³)")
    ax2.plot(n_exp, f_exp, label="O(2ⁿ)")

    ax2.set_xlabel("n (input size)")
    ax2.set_ylabel("Steps (log scale)")
    ax2.set_yscale("log")  # <- key difference
    ax2.grid(True, which="both", alpha=0.3)
    ax2.legend(loc="upper left")

    plt.tight_layout()
    plt.show()


if __name__ == "__main__":
    main()
