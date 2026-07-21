from collections import defaultdict, deque, Counter
from heapq import heappush, heappop, heapify
from itertools import permutations, accumulate, combinations, combinations_with_replacement
from math import sqrt, ceil, floor, factorial
from bisect import bisect_left, bisect_right, insort_left, insort_right
from copy import deepcopy
from operator import itemgetter
from functools import reduce, lru_cache  # @lru_cache(None)
from fractions import gcd
import sys
def input(): return sys.stdin.readline().rstrip()
def I(): return int(input())
def Is(): return (int(x) for x in input().split())
def LI(): return list(Is())
def TI(): return tuple(Is())
def IR(n): return [I() for _ in range(n)]
def LIR(n): return [LI() for _ in range(n)]
def TIR(n): return [TI() for _ in range(n)]
def S(): return input()
def Ss(): return input().split()
def LS(): return list(S())
def SR(n): return [S() for _ in range(n)]
def SsR(n): return [Ss() for _ in range(n)]
def LSR(n): return [LS() for _ in range(n)]
sys.setrecursionlimit(10**6)
MOD = 10**9+7
INF = 10**18
# ----------------------------------------------------------- #

n = I()

if n == 1:
    print(0)
    exit()

def prime_factorize_tuple(n):
    ret = []
    tmp = n
    for i in range(2, ceil(sqrt(n))):
        if tmp % i == 0:
            count = 0
            while tmp % i == 0:
                count += 1
                tmp //= i
            ret.append((i, count))

    if tmp != 1:
        ret.append((tmp, 1))

    if not ret:
        ret.append([n, 1])  # n is prime

    return ret

def check(n, x):
    return n*(n+1)//2 <= x

def meguru_bisect(ng, ok, x):
    """
    初期値のng,okを受け取り, check=>Trueを満たす最大値(最小値)を返す
    条件を満たす最大値を求める場合、初期値は(ng:上限の外, ok:下限の外)   例) 10**9+1, -1
    条件を満たす最小値を求める場合、初期値は(ng:下限の外, ok:上限の外)   例) -1, 10**9+1
    上限の外や下限の外が返ってくる場合は条件を満たす値が範囲内になかったことを示すので、例外処理が必要
    """
    while abs(ok - ng) > 1:
        mid = (ok + ng) // 2
        if check(mid, x):
            ok = mid
        else:
            ng = mid
    return ok

ans = 0
for p, x in prime_factorize_tuple(n):
    ans += meguru_bisect(10**13, 0, x)

print(ans)
