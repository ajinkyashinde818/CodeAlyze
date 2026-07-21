import bisect,copy,heapq,itertools,string
from collections import *
from math import *
import sys
def input() : return sys.stdin.readline().strip()
def INT()   : return int(input())
def MAP()   : return map(int,input().split())
def LIST()  : return list(MAP())

n, k, s = MAP()
ans = [0]*n

for i in range(n):
        if(i < k):
                ans[i] = s
        else:
                if(s == 1e9):
                        ans[i] = 1
                else:
                        ans[i] = s + 1
print(*ans)
