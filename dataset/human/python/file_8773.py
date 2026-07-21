import numpy as np
K, N = map(int, input().split())
A = list(map(int, input().split()))
A = np.array(A)
ma = 0
for i in range(N-1):
  if A[i+1] - A[i] > ma:
    ma = A[i+1] -A[i]
if K -(A[N-1] -A[0]) > ma:
  ma = K -(A[N-1] -A[0])
print(K -ma)
