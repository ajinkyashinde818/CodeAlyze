N=int(input())
import numpy as np
A=np.array(list(map(int,input().split())))
m=np.sum(A<0)
flag=np.any(A==0)
A=np.abs(A)
ans=np.sum(A)
if (m%2==1)and(not flag):
  x=np.min(A)
  ans-=x*2

print(ans)
