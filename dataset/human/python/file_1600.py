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

n, m = MAP()
a = [input() for i in range(n)]
b = [input() for i in range(m)]

ans = "No"
for i in range(n-m+1):
    for j in range(n-m+1):
        for k in range(m):
            for l in range(m):
                if a[i+k][j+l] != b[k][l]:
                    break
            else:
                continue
            break
        else:
            ans = "Yes"
            break
    else:
        continue
    break

print(ans)
