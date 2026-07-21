import numpy as np

k,n = map(int,input().split())
a = list(map(int,input().split()))
temp =a[0]
a.append(temp)
base = np.empty(n)

for i in range(n):
  if i == n-1:
    base[i] = (k-a[i]) + a[0]
    break
    
  base[i] = a[i+1] - a[i]
  
print(k - int(np.max(base)))
