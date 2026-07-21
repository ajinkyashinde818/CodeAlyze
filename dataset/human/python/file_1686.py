import numpy as np
n,m=map(int,input().split())
a=np.array([[0 if i!="." else 1 for i in input()]for j in range(n)])
b=np.array([[0 if i!="." else 1 for i in input()]for j in range(m)])
ans = 'No'
for i in range(n-m+1):
  for j in range(n-m+1):
    if np.all(b == a[i:i+m,j:j+m]):
      ans = 'Yes'      
print(ans)
