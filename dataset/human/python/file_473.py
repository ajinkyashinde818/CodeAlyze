import numpy as np
N = (int(input())+1)
A = [int(i) for i in input().split()]
B = np.abs(A)
C = 0
for i in range(N-1):
  if A[i]<0 : C+=1

C %= 2
min = min(B)

if C==0: print(sum(B))
else : print(sum(B)-min*2)
