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

r,g,b,n = I()
a = []
a.append(r)
a.append(g)
a.append(b)
a.sort()
a[0],a[1],a[2] = r,g,b

mx_b = n//b
amari = n%b
for i in range(n//r + 1):
    for j in range((n-r*i)//g + 1):
        if (n-r*i-g*j) % b == 0:
            cnt += 1

print(cnt)
