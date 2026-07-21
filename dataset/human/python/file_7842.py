import sys
import math
import itertools
import bisect
from copy import copy
from collections import deque,Counter
from decimal import Decimal
def s(): return input()
def i(): return int(input())
def S(): return input().split()
def I(): return map(int,input().split())
def L(): return list(input().split())
def l(): return list(map(int,input().split()))
def lcm(a,b): return a*b//math.gcd(a,b)
sys.setrecursionlimit(10 ** 9)
mod = 10**9+7

N,K,S = I()
ruiseki = [0]*(N+1)
for i in range(N):
    if K:
        ruiseki[i+1] = ruiseki[i]+S
        K -= 1
    else:
        ruiseki[i+1] = 10**15
ans = [10**9]*N
if S == 10**9:
    ans = [10**9-17]*N
for i in range(N-1,-1,-1):
    if ruiseki[i+1] <= 10**14:
        ans[i] = ruiseki[i+1]-ruiseki[i]
print(*ans)
