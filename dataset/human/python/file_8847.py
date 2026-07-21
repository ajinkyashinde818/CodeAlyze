import sys
from math import factorial
from fractions import Fraction
import heapq, bisect, fractions
import math
import itertools
sys.setrecursionlimit(10 ** 5 + 10)
INF = 10**15 +5
def input(): return sys.stdin.readline().strip()
def INT(): return int(input())
def MAP(): return map(int, input().split())
def LIST(): return list(map(int, input().split()))

k, n = MAP()
a = LIST()
dis = [a[i+1]-a[i] for i in range(n-1)]
dis.append(k-a[n-1]+a[0])

print(sum(dis)-max(dis))
