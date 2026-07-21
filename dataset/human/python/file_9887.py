from sys import stdin
import sys
import math
from functools import reduce
import functools
import itertools
from collections import deque

n,k = [int(x) for x in stdin.readline().rstrip().split()]
a = [0] + [int(x) for x in stdin.readline().rstrip().split()]

m = 0
b = [1]
visited = [-1 for i in range(n+1)]

c = 1
visited[1] = 1
for i in range(n):
    c = a[c]
    if visited[c] != 1:
        b.append(c)
        visited[c] = 1
        if i == k-1:
            print(c)
            sys.exit()
    else:
        break

idx = b.index(c)
bn = len(b[idx:])
sn = len(b[:idx])

# print(b,idx,sn,bn)
kk = (k-sn) % bn
print(b[idx+kk])
