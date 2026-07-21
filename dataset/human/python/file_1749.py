import numpy as np
N,M = map(int,input().split())
A = np.array([list(input()) for _ in range(N)])
B = np.array([list(input()) for _ in range(M)])

hantei = False

for i in range(N-M+1):
  for j in range(N-M+1):
    C=np.array(A[i:i+M,j:j+M])
    if (C==B).all():
      hantei = True
print('Yes' if hantei else 'No')
