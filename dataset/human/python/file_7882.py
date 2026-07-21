import numpy as np

N,K,S = map(int,input().split())
A = np.zeros(N,dtype="int64")
if S == 1000000000:
  for i in range (0,K):
    A[i] = S
  for i in range (K,N):
    A[i] = S - 1
else:
  for i in range (0,K):
    A[i] = S
  for i in range (K,N):
    A[i] = S + 1

for i in range (0,N):
  print(A[i], end=" ")
