import itertools
import functools
import math
from collections import Counter



K,N = map(int,input().split())
A = list(map(int,input().split()))
for i in range(N):
    A.append(K+A[i])

sum = 0
chk = -1

for i in range(N):
    if sum < A[i+1] - A[i]:
        sum  = A[i+1] - A[i]
        chk = (i + 1) % N


print(K-sum)
