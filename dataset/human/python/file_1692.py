import numpy as np
a,b=map(int,input().split())
def sn(x):
  if x==".":
    return 0
  else:
    return 1
c=np.array([list(map(sn,list(input()))) for i in range(a)])
d=np.array([list(map(sn,list(input()))) for i in range(b)])

for i in range(a-b+1):
  for j in range(a-b+1):
    if np.allclose(c[i:b+i,j:b+j],d):
      print("Yes")
      exit()
else:
  print("No")
