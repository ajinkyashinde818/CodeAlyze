import sys
input = sys.stdin.readline
sys.setrecursionlimit(10000000)
from collections import defaultdict
from bisect import *
mod = 10**9+7

N, K, S = map(int, input().split())
if S == 10**9:
    A = [S]*K + [1]*(N-K)
else:
    A = [S]*K + [S+1]*(N-K)
print(*A)
