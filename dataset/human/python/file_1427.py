import sys, re, os
from collections import deque, defaultdict, Counter
from math import ceil, sqrt, hypot, factorial, pi, sin, cos, radians, acos, atan, asin
from itertools import permutations, combinations, product, accumulate
from operator import itemgetter, mul
from copy import deepcopy
from string import ascii_lowercase, ascii_uppercase, digits
from fractions import gcd
def input(): return sys.stdin.readline().strip()
def STR(): return input()
def INT(): return int(input())
def MAP(): return map(int, input().split())
def S_MAP(): return map(str, input().split())
def LIST(): return list(map(int, input().split()))
def S_LIST(): return list(map(str, input().split()))
sys.setrecursionlimit(10 ** 9)
inf = sys.maxsize
mod = 10 ** 9 + 7

n = INT()
a = LIST()
s = sum(a)
arr = [0 for _ in range(n)]
arr[0] = a[0]
ans = [inf for _ in range(n)]
ans[0] = abs(a[0] - (s - a[0]))
for i in range(1, n - 1):
    arr[i] = arr[i - 1] + a[i]
    ans[i] = abs(arr[i] - (s - arr[i]))
print(min(ans))
