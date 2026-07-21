from collections import defaultdict, Counter
from itertools import product, groupby, count, permutations, combinations
from math import pi, sqrt
from collections import deque
from bisect import bisect, bisect_left, bisect_right
INF = float("inf")


def main():
    N = int(input())
    a_list = list(map(int, input().split()))
    total = sum(a_list)
    d = (1 + N) * N // 2
    if total % d != 0:
        print("NO")
        return
    k = total // d
    for i in range(N - 1):
        diff = a_list[i + 1] - a_list[i]
        if diff > k or (k - diff) % N != 0:
            print("NO")
            return
    print("YES")


if __name__ == '__main__':
    main()
