from sys import stdin, setrecursionlimit
input = stdin.buffer.readline
setrecursionlimit(10 ** 7)

from heapq import heappush, heappop
from bisect import bisect_left, bisect_right
from collections import deque, defaultdict, Counter
from itertools import combinations, permutations, combinations_with_replacement
from itertools import accumulate
from math import ceil, sqrt, pi, radians, sin, cos

def factorization(n):
    arr = []
    temp = n
    for i in range(2, int(-(-n ** 0.5 // 1)) + 1):
        if temp % i == 0:
            cnt = 0
            while temp % i == 0:
                cnt += 1
                temp //= i
            arr.append([i, cnt])
    if temp != 1:
        arr.append([temp, 1])
    if arr == []:
        arr.append([n, 1])
    return arr

def g(n):
    ret = 0
    for i in range(1, 100):
        n -= i
        if n < 0:
            break
        ret += 1
    return ret

MOD = 10 ** 9 + 7
INF = 10 ** 18

N = int(input())

if N == 1:
    print(0)
else:
    f = factorization(N)
    f.sort(key = lambda x: -x[1])
    len_f = len(f)

    answer = 0
    for i in range(len_f):
        answer += g(f[i][1])
    print(answer)
