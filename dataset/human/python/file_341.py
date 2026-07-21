from sys import stdin
from collections import deque, defaultdict as ddic
from itertools import combinations, permutations, product
import bisect
import heapq


rs = lambda: stdin.readline().strip()
ri = lambda: int(rs())
rsl = lambda: stdin.readline().split()
rim = lambda: map(int, rsl())
ril = lambda: list(rim())

N = ri()
A = list(rim())
B = [abs(elem) for elem in A]

low = min(B)
minus = 0
for i in range(len(A)):
    if A[i] < 0:
        minus += 1

if minus % 2 == 0:
    print(sum(B))
else:
    print(sum(B) - (low*2))
