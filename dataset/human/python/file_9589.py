import numpy as np
N,K=map(int,input().split())
A=list(map(int,input().split()))
C=[1]
s=set([1])
for i in range(N):
  if A[C[i]-1] in s:
    l=C.index(A[C[i]-1])+1
    break
  else:
    C.append(A[C[i]-1])
    s.add(A[C[i]-1])
if K+1<=l:
  print(C[K])
else:
  print(C[l-1+(K+1-l)%(len(C)-l+1)])
