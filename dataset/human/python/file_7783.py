import sys, math
def input():
    return sys.stdin.readline()[:-1]
from itertools import permutations, combinations
from collections import defaultdict, Counter
from math import factorial

sys.setrecursionlimit(10**7)
N, K, S = map(int, input().split())

nS = 10**9 - 1
nnS = 10**9 - 2

A = [S]*K
if S != nS:
    AA = [nS]*(N-K)
else:
    AA = [nnS]*(N-K)

A = A + AA
print(*A)
