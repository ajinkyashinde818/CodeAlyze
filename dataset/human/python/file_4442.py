import bisect
import collections
import copy
import functools
import heapq
import math
import sys
from collections import deque
from collections import defaultdict
input = sys.stdin.readline
MOD = 10**9+7

N = int(input())
def factorization(n):
    arr = []
    temp = n
    for i in range(2, int(-(-n**0.5//1))+1):
        if temp % i == 0:
            cnt = 0
            while temp % i ==0:
                cnt += 1
                temp //= i
            arr.append([i, cnt])

    if temp != 1:
        arr.append([temp, 1])

    if arr == []:
        arr.append([n, 1])

    return arr

if N == 1:
    print(0)
else:
    ans = 0
    l = factorization(N)
    for i in range(len(l)):
        now = l[i][1]
        c = 1
        while now-c >= 0:
            now -= c
            ans += 1
            c += 1
    print(ans)
