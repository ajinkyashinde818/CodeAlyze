import numpy as np
N, M = map(int, input().split())
A = np.array([list(input()) for i in range(N)])
B = np.array([list(input()) for i in range(M)])

for k in range(N-M+1):
  for l in range(N-M+1):
    C = A[k:k+M,l:l+M]
    if (B==C).all():
      print('Yes')
      exit()
print('No')
