import numpy as np

N = int(input())
A = list(map(int, input().split()))

A = np.array(A)
A_cumsum = np.cumsum(A)

solver = []
for i in range(N-1):
  snuke = A_cumsum[i]
  racoon = A_cumsum[-1] - A_cumsum[i]
  solver.append(np.abs(snuke - racoon))
  
print(min(solver))
