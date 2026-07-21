import numpy as np
       
N = input()
A = np.array([int(x) for x in input().split(" ")])

if len(np.where(A<0)[0])%2 == 0:
  print(np.abs(A).sum())
else:
  print(np.abs(A).sum() - np.abs(A).min()*2)
