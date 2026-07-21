import numpy as np
n,m=map(int,input().split())
L1,L2=[],[]
for s in range(n):
  L1.append(list(input()))
for s in range(m):
  L2.append(list(input()))
L1,L2=np.array(L1),np.array(L2)
for s in range(n-m+1):
  for t in range(n-m+1):
#    print(L1[s:s+m,t:t+m],L2)
    if np.all(L1[s:s+m,t:t+m]==L2):
      print("Yes")
      exit()
print("No")
