n=int(input())
a=list(map(int,input().split()))
from itertools import accumulate
s=list(accumulate(a))
a_sum=sum(a)
ans=10**18
if n==2:
  print(abs(a[0]-a[1]))
  exit(0)
for i in range(1,n-1):
  x=s[i]
  y=a_sum-x
  ans=min(ans,abs(x-y))
print(ans)
