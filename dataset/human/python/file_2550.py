import math
import sys
from collections import deque
a,b=map(int,input().split())
l=[list(map(int,input().split())) for i in range(a)]
ans=10**20
for i in range(2**a):
  s=0
  count=0
  keep1=0
  keep2=0
  t=True
  for j in range(a):
    if i>>j &1:
      s+=l[a-1-j][0]*100*(a-j)+l[a-1-j][1]
      count+=l[a-1-j][0]
    else:
      if t:
        keep1=100*(a-j)
        keep2=l[a-1-j][0]-1
        t=False
  if s+keep1*keep2>=b:
    if s>=b:
      if ans>count:
        ans=count
    else:
      p=count+math.ceil((b-s)/keep1)
      if p<ans:
        ans=p
print(ans)
