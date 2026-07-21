import numpy as np
import scipy.sparse as sps
import scipy.misc as spm
import collections as col
import functools as func
import itertools as ite
import fractions as frac
import math as ma
from math import cos,sin,tan,sqrt
import cmath as cma
import copy as cp
import sys
import re
sys.setrecursionlimit(10**7)
EPS = sys.float_info.epsilon
PI = np.pi; EXP = np.e; INF = np.inf
MOD = 10**9 + 7

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
def adj(n): return [[] for _ in range(n)]

n,m = imap()
a = [[int(elm=="#") for elm in list(input())] for i in range(n)]
b = [[int(elm=="#") for elm in list(input())] for i in range(m)]
a,b = np.array(a),np.array(b)
#print(a)
#print(b)

flag = 0
for i in range(n-m+1):
    for j in range(n-m+1):
        tmp = a[i:i+m, j:j+m]
        if (tmp == b).all(): flag = 1; break

ans = "Yes" if flag else "No"
print(ans)
