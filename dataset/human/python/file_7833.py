from sys import stdin, setrecursionlimit
from collections import Counter, deque, defaultdict
from math import floor, ceil
from bisect import bisect_left
from itertools import combinations
setrecursionlimit(100000)

INF = int(1e10)
MOD = int(1e9 + 7)

def main():
    from builtins import int, map
    N, K, S = map(int, input().split())
    # al + ... ar = SがちょうどK個
    # S S S S S 1 1 1 1 1 1みたいな感じでいい?
    if S == 10 ** 9:
        ans = [S] * K + [1] * (N - K)
    else:
        ans = [S] * K + [S + 1] * (N - K)
    print(*ans)

if __name__ == '__main__':
    main()
