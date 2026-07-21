from math import ceil,floor,factorial,gcd,sqrt,log2,cos,sin,tan,acos,asin,atan,degrees,radians,pi,inf,comb
from itertools import accumulate,groupby,permutations,combinations,product,combinations_with_replacement
from collections import deque,defaultdict,Counter
from bisect import bisect_left,bisect_right
from operator import itemgetter
from heapq import heapify,heappop,heappush
from queue import Queue,LifoQueue,PriorityQueue
from copy import deepcopy
from time import time
from functools import reduce
import string
import sys
sys.setrecursionlimit(10 ** 7)
def input() : return sys.stdin.readline().strip()
def INT()   : return int(input())
def MAP()   : return map(int,input().split())
def LIST()  : return list(MAP())

n, k = MAP()
n += 1
a = [0] + LIST()
# b[1]: 町iに到達する最小回数
b = [-1]*n

now = 1
count = 0
for i in range(n):
    if b[now] == -1:
        b[now] = count
        count += 1
        now = a[now]
    else:
        offset = b[now]
        loop = count - b[now]
        break
if k <= offset:
    targ = k
else:
    targ = (k-offset) % loop + offset

for i in range(1, n):
    if b[i] == targ:
        print(i)
        exit()
