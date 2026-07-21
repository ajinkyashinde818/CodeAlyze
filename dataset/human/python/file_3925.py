ni = lambda: int(input())
nm = lambda: map(int, input().split())
nl = lambda: list(map(int, input().split()))

import math

n = ni()


nn = 10**6+2
divs=[0]*nn
ans=0

for i in range(2,nn):
  while n%i==0:
    divs[i]+=1
    n//=i

# for i in range(nn):
#   if divs[i]>0:
#     print('{} {}'.format(i,divs[i]))


if n!=1:
  ans+=1

for i in range(nn):
  for j in range(1,nn):
    if divs[i]<j:
      break
    divs[i]-=j
    ans+=1


print(ans)
