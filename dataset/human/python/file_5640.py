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

s = input()

i = 0
ans = 0
while s:
    if s[0] == s[-1]:
        s = s[1:-1]
    elif s[0] == 'x':
        s = s[1:]
        ans += 1
    elif s[-1] == 'x':
        s = s[:-1]
        ans += 1
    else:
        print(-1)
        exit()
print(ans)
