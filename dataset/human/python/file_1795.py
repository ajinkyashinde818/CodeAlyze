import numpy as np
n, m=map(int,input().split())

n_grid=np.array([list(input()) for _ in range(n)])
m_grid=np.array([list(input()) for _ in range(m)])

found=False
for i in range(n-m+1):
  for j in range(n-m+1):
    if (m_grid == n_grid[i:i+m, j:j+m]).all():
      found=True
      break
if found:
  print("Yes")
else:
  print("No")
