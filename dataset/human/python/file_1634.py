import sys
import itertools
sys.setrecursionlimit(1000000000)
from heapq import heapify,heappop,heappush,heappushpop
import math
import collections
MOD = 10**9 + 7

n,m = map(int,input().split())
li = [input() for i in range(n)]
li2 = [input() for i in range(m)]

d = []
for i in range( n - m + 1):
    for j in range( n - m + 1):
        koho = []
        for k in range(m):
            c = ""
            for l in range(m):
                c += li[i+k][j+l]
            koho.append(c)
        if koho == li2:
            print("Yes")
            sys.exit()
print("No")
