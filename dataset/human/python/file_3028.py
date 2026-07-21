import numpy as np
import scipy.sparse as sps
import scipy.misc as spm
import collections as col
import functools as func
import itertools as ite
import fractions as frac
import math as ma
from math import cos,sin,tan
import cmath as cma
import copy as cp
import sys
import re
def sinput(): return sys.stdin.readline().strip()
def iinput(): return int(sinput())
def imap(): return map(int, sinput().split())
def fmap(): return map(float, sinput().split())
def iarr(n=0):
    if n: return [0 for _ in range(n)]
    else: return list(imap())
def farr(): return list(fmap())
def sarr(n=0):
    if n: return ["" for _ in range(n)]
    else: return sinput().split()
def barr(n): return [False for _ in range(n)]
def adj(n): return [[] for _ in range(n)]
sys.setrecursionlimit(10**7)
MOD = 10**9 + 7; EPS = sys.float_info.epsilon
PI = np.pi; EXP = np.e; INF = np.inf

def prime(n):
    ans = []
    for i in range(2,int(n**0.5)+1):
        while n%i == 0:
            n //= i
            ans.append(i)
    if n > 1: ans.append(n)
    return ans

n = iinput()
primes = prime(n)
cnt = col.Counter(primes)

ans = 0
for key,val in cnt.items():
    i = 1
    while 1:
        val -= i
        if val < 0: break
        ans += 1
        i += 1

print(ans)
