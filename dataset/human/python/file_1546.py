N,M=map(int,input().split())
import numpy as np
A=np.array([list(input()) for _ in range(N)])
B=np.array([list(input()) for _ in range(M)])
ans='No'
for i in range(N-M+1):
  for j in range(N-M+1):
    if (A[i:i+M,j:j+M]==B).all():
      ans='Yes'
      break
  else:continue
  break
    
    
print(ans)
