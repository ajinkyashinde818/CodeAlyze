import numpy as np
import sys
readline = sys.stdin.buffer.readline
K, N = map(int, readline().split())
A = list(map(int,input().split()))
N1= A[0]+K-A[N-1]

for i in range(1, N):
 N1=max(N1,A[i]-A[i-1])

print(K-N1)
