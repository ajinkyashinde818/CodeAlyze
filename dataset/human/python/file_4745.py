import sys
import math
import numpy as np
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
INF = 10**9
mod = 10**9+7

S = list(s())
T = list(s())
if S == T:
    print('No')
    exit()
S.sort()
T.sort(reverse=True)
for i in range(min(len(S),len(T))):
    if ord(S[i]) > ord(T[i]):
        print('No')
        exit()
    if ord(S[i]) < ord(T[i]):
        print('Yes')
        exit()
if len(S) > len(T):
    print('No')
else:
    print('Yes')
