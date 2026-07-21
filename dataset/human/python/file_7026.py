from collections import deque
import numpy as np
 
S=deque(input())
Q=int(input())
count = 0
L=np.array([input().split() for _ in range(Q)])
 
for i in range(Q):
  l=L[i]
  if len(l)==1:
    count+=1
    continue
  elif len(l)==3:
    F=int(l[1])
    C=l[2]
    if (count%2==1) ^ (F==1):
      S.appendleft(C)
    else:
      S.append(C)
 
if count%2==1:
  S.reverse()
print(''.join(S))
