N=int(input())
import numpy as np
A=np.array(input().split(),dtype=int)
A=np.cumsum(A)

ans=10**9*2+1
for i in range(N-1):
  ans=min(ans,abs(A[i]-(A[len(A)-1]-A[i])))
print(ans)
