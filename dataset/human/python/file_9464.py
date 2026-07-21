import numpy as np
n,m=list(map(int,input().split()))
a=np.array(list(map(int,input().split())))
b=np.zeros(n)

mod = 2*n

tmp = 0
for i in range(mod):
  if b[tmp] == 2:
    break
  b[tmp] += 1
  tmp = a[tmp] -1
  
s = len(a[b==1])
t = len(a[b==2])

if m > s:
  m = (m-s)%t + s
tmp = 0
for i in range(m):
  tmp = a[tmp] -1
  
print(tmp+1)
