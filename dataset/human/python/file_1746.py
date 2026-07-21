import numpy as np
N,M = map(int,input().split())
A = np.array([list(input()) for n in range(N)])
B = np.array([list(input()) for m in range(M)])
a = "No"

for i in range(N-M+1):
  for j in range(N-M+1):
    if (A[i:i+M,j:j+M]==B).all():
      a = "Yes"

print(a)
