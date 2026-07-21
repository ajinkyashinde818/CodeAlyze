import numpy as np
N = input()
N = int(N)
A = np.hstack([int(a) for a in input().split()])
B = np.hstack([int(a) for a in input().split()])
C = np.hstack([int(a) for a in input().split()])

score = 0
for i in range(N-1):
  score += B[A[i]-1]
  if A[i+1] - A[i] == 1:
    score += C[A[i]-1]

score += B[A[N-1]-1]
print(score)
