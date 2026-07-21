import sys, re
import math
 
def input(): return sys.stdin.readline().strip()
def INT(): return int(input())
def MAP(): return map(int, input().split())
def LIST(): return list(map(int, input().split()))
sys.setrecursionlimit(10 ** 9)
INF = float('inf')
MOD = 10 ** 9 + 7

# -*- coding: utf-8 -*-

k, n = MAP()
a = LIST()

b = []

for x in range(0, n - 1):
    b.append(a[x + 1] - a[x])

b.append(k - a[n - 1] + a[0])

print(k - max(b))
