import numpy as np
n,k,s = map(int,input().split())
a=np.arange(n)
if k>0 and s<1000000000:
  a[:k]=s
  a[k:]=s+1
elif k>0 and s>=1000000000:
  a[:k]=s
  a[k:]=s-1
elif k==0 and s>=1000000000:
  a[:]=s-1
else:
  a[:]=s+1
for s in a:
  print(s, end =" ")
