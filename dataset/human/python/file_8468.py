import sys
import math
import numpy

K , N = map(int,input().split())
A = list(map(int,input().split()))

sorted(A)

total = K

for i in range(N):
    tmp =0
    if i < N -1:
        tmp = A[i+1] - A[i]
        total = min(K-tmp , total)
    else:
        tmp = K - A[i] + A[0]
        total = min(K-tmp , total)


print(total)
