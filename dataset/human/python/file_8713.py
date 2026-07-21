import sys
import numpy as np


def main():
    input = sys.stdin.buffer.readline
    k, n = map(int, input().split())
    a = np.array(list(map(int, input().split())))
    a_dash = a[list(range(1, n)) + [0]]
    a[-1] -= k
    dist = np.abs(a - a_dash)
    max_dist = np.max(dist)
    print(k - max_dist)


if __name__ == "__main__":
    main()
