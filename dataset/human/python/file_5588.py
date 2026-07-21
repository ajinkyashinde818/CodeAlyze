from collections import defaultdict, Counter
from itertools import product, groupby, count, permutations, combinations
from math import pi, sqrt
from collections import deque
from bisect import bisect, bisect_left, bisect_right
INF = float("inf")


def main():
    s = input()
    ans = 0

    left, right = 0, len(s) - 1
    while left < right:
        l, r = s[left], s[right]
        if l == r:
            left += 1
            right -= 1
        elif l != "x" and r != "x":
            ans = -1
            break
        elif l == "x" and r != "x":
            ans += 1
            left += 1
        elif l != "x" and r == "x":
            ans += 1
            right -= 1

    print(ans)


if __name__ == '__main__':
    main()
