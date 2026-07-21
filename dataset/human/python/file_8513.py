import numpy as np

K, N = map(int, input().split())
A = list(map(int, input().split()))
A_dist = [0]*N

for i in range(N-1):
    A_dist[i] = A[i+1]-A[i]
    
A_dist[N-1] = (K-A[N-1])+A[0]


A_dist_max = max(A_dist)
print(K-A_dist_max)
