import bisect
import numpy as np

N=int(input())

A=list(map(int,input().split()))
A.sort()
minus=bisect.bisect_left(A,0)
Aabs=np.abs(np.array(A))
if minus%2==0 or (minus!=N and A[minus]==0):
  print(np.sum(Aabs))
else:
  Aabs_sort=np.sort(Aabs)
  print(np.sum(Aabs)-(2*Aabs_sort[0]))
