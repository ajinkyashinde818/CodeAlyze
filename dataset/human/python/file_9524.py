import re
import sys
import math
import itertools
import bisect
from copy import copy
from collections import deque,Counter
from decimal import Decimal
import functools
def v(): return input()
def k(): return int(input())
def S(): return input().split()
def I(): return map(int,input().split())
def X(): return list(input())
def L(): return list(input().split())
def l(): return list(map(int,input().split()))
def lcm(a,b): return a*b//math.gcd(a,b)
sys.setrecursionlimit(10 ** 9)
mod = 10**9+7
cnt = 0
ans = 0
inf = float("inf")

n,k=I()
a = l()
town = []
num = [0]*(n+1)
cnt = 1
num[0]=1

for i in range(n):
    num[a[cnt-1]] += 1
    if num[a[cnt-1]] == 2:
        ans = a[cnt-1]
        p = town.index(ans)
        b = town[p:]
        x = len(town)
        y = len(b)
        q = k-x+y
        if y == 0:
            print(town[n-1])
            sys.exit()
        if q < 0:
            print(town[k-1])
            sys.exit()
        z = q%y
        print(b[z-1])
        sys.exit()
        break
    town.append(a[cnt-1])
    cnt = a[cnt-1]
