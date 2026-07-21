import numpy as np

N=int(input())
A=np.array(list(map(int, input().split())))

if np.sum(A<0)%2==0:
  print(np.sum(np.abs(A)))
else:
  print(np.sum(np.abs(A))-2*np.min(np.abs(A)))
