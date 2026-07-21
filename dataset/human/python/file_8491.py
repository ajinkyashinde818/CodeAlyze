import numpy as np

K,N = [int(i) for i in input().split()]
A = [int(i) for i in input().split()]
B = []
maxdist = 0
for i in range(N-1):
    B.append(A[i+1]-A[i])
    if B[-1]>maxdist:
        maxdist = B[-1]

if A[0]+K-A[-1]>maxdist:
    maxdist = A[0]+K-A[-1]

print(K - maxdist)
