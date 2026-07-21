import sys
from bisect import *
from heapq import *
from collections import *
from itertools import *
from functools import *

sys.setrecursionlimit(100000000)
input = lambda: sys.stdin.readline().rstrip()

N = int(input())
A = list(map(lambda s: int(s) - 1, input().split()))
B = list(map(int, input().split()))
C = list(map(int, input().split()))

ans = 0
for i, a in enumerate(A):
    ans += B[a]
    if i > 0 and A[i - 1] == a - 1:
        ans += C[a - 1]
print(ans)
