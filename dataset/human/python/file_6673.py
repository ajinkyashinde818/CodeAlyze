import math
import random
import sys
from bisect import bisect_left, bisect_right
from collections import Counter, defaultdict, deque
from functools import lru_cache, reduce
from heapq import heapify, heappop, heappush
from itertools import (chain, combinations, combinations_with_replacement,
                       permutations)

MAX_INT = 2**62-1
sys.setrecursionlimit(10**7)

input = sys.stdin.readline


def read_n_int():
    return map(int, input().split())


def main():
    s = input().strip()
    q = int(input())
    queue = deque(s)
    is_reversed = 0

    for _ in range(q):
        t, *x = input().strip().split()
        # print(t, x, queue)
        if t == '1':
            is_reversed ^= 1
        else:
            where, c = x
            where = int(where) & 1
            if where ^ is_reversed:
                queue.appendleft(c)
            else:
                queue.append(c)
    if is_reversed:
        queue.reverse()

    print(''.join(queue))


if __name__ == "__main__":
    main()
