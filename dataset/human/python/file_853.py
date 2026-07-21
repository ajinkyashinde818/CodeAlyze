import sys
from operator import itemgetter
from collections import deque, Counter
from itertools import permutations, combinations
from heapq import heapify, heappop, heappush
from bisect import bisect, bisect_left

def solve():
    input = sys.stdin.readline
    N, R = map(int, input().split())
    if N < 10: R += 100 * (10 - N)
    print(R)

    return 0

if __name__ == "__main__":
    solve()
