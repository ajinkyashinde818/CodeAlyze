from itertools import product
import numpy as np

N, M = map(int, input().split())
A = [input() for _ in range(N)]
B = [input() for _ in range(M)]

for i, j in product(range(N-M+1), repeat=2):
  if np.prod([A[i+k][j:j+M] == B[k] for k in range(M)]):
    print('Yes')
    break
else:
  print('No')
