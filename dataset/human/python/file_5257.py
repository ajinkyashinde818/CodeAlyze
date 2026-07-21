import bisect,copy,heapq,itertools,string
from collections import *
from math import *
import sys
def input() : return sys.stdin.readline().strip()
def INT()   : return int(input())
def MAP()   : return map(int,input().split())
def LIST()  : return list(MAP())

n, m = MAP()
a = [LIST() for i in range(m)]
c = [0]*(n+1)

for i in range(m):
        if a[i][0] == 1 or a[i][0] == n or a[i][1] == 1 or a[i][1] == n:
                c[a[i][0]] += 1
                c[a[i][1]] += 1

for i in range(2, n):
        if c[i] >= 2:
                print("POSSIBLE")
                exit()

print("IMPOSSIBLE")
