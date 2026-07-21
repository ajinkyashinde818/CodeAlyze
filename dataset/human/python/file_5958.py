N = int(input())
A = [int(i) for i in input().split()]
B = [int(i) for i in input().split()]
C = [int(i) for i in input().split()]

import numpy as np

ans = np.sum(B)

D = np.zeros(N-1)

for i in range(N-1):
  D[i] = A[i+1] - A[i]
  
for i in range(N-1):
  if D[i] == 1:
    x = A[i] - 1
    ans += C[x]
    
print(ans)
