from math import ceil,floor,comb,factorial,gcd,pow,sqrt,log2,cos,sin,tan,acos,asin,atan,degrees,radians,pi,inf
from itertools import accumulate,permutations,combinations,product,combinations_with_replacement
from collections import deque,defaultdict,Counter
from bisect import bisect_left,bisect_right
from operator import itemgetter
from heapq import heapify,heappop,heappush
from queue import Queue,LifoQueue,PriorityQueue
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
a = LIST()
dp = [[0]*n for i in range(2)]
# dp[0][i]: {a[i], a[i+1]}に-1を乗算しないときのa[i]までの和の最大値
# dp[1][i]: {a[i], a[i+1]}に-1を乗算したときのa[i]までの和の最大値

for i in range(n):
    if i == 0:
        dp[0][i] = a[i]
        dp[1][i] = -a[i]
    else:
        dp[0][i] = max(dp[0][i-1]+a[i], dp[1][i-1]-a[i])
        dp[1][i] = max(dp[0][i-1]-a[i], dp[1][i-1]+a[i])

print(dp[0][-1])
