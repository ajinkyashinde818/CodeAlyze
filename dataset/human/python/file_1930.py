import numpy as np

n,m=map(int,input().split())
a=np.zeros([n,n])
b=np.zeros([m,m])
map_ = {".":1,"#":-1}

for i in range(n):
  temp = list(input())
  temp = [map_[c] for c in temp]
  a[i,:] = np.array(temp)
  
for i in range(m):
  temp = list(input())
  temp = [map_[c] for c in temp]
  b[i,:] = np.array(temp)

flag=False
for i in range(n-m+1):
  for j in range(n-m+1):
    temp_a = a[i:i+m,j:j+m]
    check=np.sum(temp_a*b,axis=1)
    check=np.sum(check,axis=0)
    if check==m*m:
      flag=True
      break
    else:
      pass
if flag:
  print("Yes")
else:
  print("No")
