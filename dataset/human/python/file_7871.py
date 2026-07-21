import sys
import math
stdin = sys.stdin
mod = 10**9 + 7

ns = lambda: stdin.readline().rstrip()
ni = lambda: int(ns())
na = lambda: list(map(int, stdin.readline().split()))
sa = lambda h: [list(map(int, stdin.readline().split())) for i in range(h)]

n, k, s = na()

if s == 10**9:
    for i in range(k):
        print(10**9, end=" ")
    for i in range(n-k):
        print(1, end=" ")
else:
    for i in range(k):
        print(s, end=" ")
    for i in range(n-k):
        print(10**9, end=" ")
