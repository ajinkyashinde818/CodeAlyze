import sys
input = sys.stdin.readline
sys.setrecursionlimit(10 ** 7)
import bisect
import numpy as np

K, S = map(int, input().split())

num = 0
for x in range(K+1):
    tmp = min(S-x, K) - max(0, S-K-x)
    if tmp >= 0:
        num += tmp + 1


print(num)
