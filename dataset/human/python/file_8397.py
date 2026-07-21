import collections
import math
import numpy as np
K, N = map(int, input().split(' '))

A = sorted(list(map(int, input().split(' '))))
for i in range(N):
    A.append(A[i]+K)


m = float('inf')

for i in range(N):
    kyori = A[i+N-1]-A[i]
    m = min(m, kyori)
print(m)
