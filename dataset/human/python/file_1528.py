import numpy as np
n,m=map(int,input().split())
a=np.array([list(input())for i in range(n)])
b=np.array([list(input())for i in range(m)])
d=n-m+1
for i in range(d):
 for j in range(d):
  if (a[i:i+m,j:j+m]==b).all():print("Yes");exit()
print("No")
