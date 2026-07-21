import numpy as np
n, m = map(int, input().split())

X = [input() for _ in range(n)]
np_x = np.zeros((n, n), dtype=int)
for i in range(n):
  for j in range(n):
    np_x[i, j] = X[i][j] == '.'
Y = [input() for _ in range(m)]
np_y = np.zeros((m, m), dtype=int)
for i in range(m):
  for j in range(m):
    np_y[i, j] = Y[i][j] == '.'

for i in range(n-m+1):
  for j in range(n-m+1):
    if np.all(np_x[i:i+m, j:j+m] == np_y):
      print('Yes')
      exit()
else:
  print('No')
