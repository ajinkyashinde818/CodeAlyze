import numpy as np
n = int(input())
l = np.array(list(map(int,input().split()))).astype("i")

m = np.sum(l < 0)

if m % 2 == 0:
  print(np.sum(np.abs(l)))
else:
  print(np.sum(np.abs(l)) - 2 * np.min(np.abs(l)))
