import sys
import bisect
import itertools
import collections
import fractions
import heapq
import math
from operator import mul
from functools import reduce
from functools import lru_cache


def solve():
    readline = sys.stdin.buffer.readline
    mod = 10 ** 9 + 7
    N = int(readline())
    if N % 2 == 1:
        print(0)
    else:
        count2 = 0
        count5 = 0
        compare = 1
        while N >= compare * 2:
            compare *= 2
            count2 += N // compare
        compare = 1
        N //= 2
        while N >= compare * 5:
            compare *= 5
            count5 += N // compare
        ans = min(count2, count5)
        print(ans)



if __name__ == '__main__':
    solve()
