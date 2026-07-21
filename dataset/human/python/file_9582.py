from copy import copy, deepcopy
from collections import Counter
from math import sqrt, floor, factorial
from itertools import permutations, combinations, combinations_with_replacement
from operator import mul
from functools import reduce
import bisect

MOD = 10**9 + 7
INF = float('inf')

N, K = list(map(int, input().split()))

A = list(map(int, input().split()))

A = [A[i]-1 for i in range(len(A))]

mem = [0]*N
mem2 = [0]*N

idx = 0
count1 = 0
while True:
    mem[idx] += 1
    if mem[idx] == 2:
        break
    count1 += 1
    idx = A[idx]


idx2 = idx
count2 = 0

count2 += 1
idx2 = A[idx2]

while True:
    if idx2 == idx:
        break
    count2 += 1
    idx2 = A[idx2]

tmp = count1 - count2

if tmp >= K:
    ans = 0
    for _ in range(K):
        ans = A[ans]
else:
    e = (K - tmp) % count2 + tmp
    ans = 0
    for _ in range(e):
        ans = A[ans]

print(ans+1)
