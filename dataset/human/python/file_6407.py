from math import ceil,floor,comb,factorial,gcd,pow,sqrt,log2,cos,sin,tan,acos,asin,atan,degrees,radians,pi,inf
from itertools import accumulate,permutations,combinations,product,combinations_with_replacement
from collections import deque,defaultdict,Counter
from bisect import bisect_left,bisect_right
from operator import itemgetter
from heapq import heapify,heappop,heappush
from copy import deepcopy
from time import time
import string
import sys
sys.setrecursionlimit(10 ** 7)
def input() : return sys.stdin.readline().strip()
def INT()   : return int(input())
def MAP()   : return map(int,input().split())
def LIST()  : return list(MAP())

n = INT()
ans = 0

if n % 2 == 0:
    c5 = 0
    c2 = 0
    for i in range(30,0,-1):
        c5 += i*(n//(2*5**i) - n//(2*5**(i+1)))
    for i in range(60,0,-1):
        c2 += i*(n//(2**i) - n//(2**(i+1)))
    ans = min(c5, c2)

print(ans)
