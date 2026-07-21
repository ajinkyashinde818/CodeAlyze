n=int(input())
s=str(input())
s=list(s)
import collections
c=collections.Counter(s)
values, counts = zip(*c.most_common())
temp=list(counts)
l=len(temp)
ans=1
for i in range(l):
  ans=ans*(temp[i]+1)
print((ans-1)%(10**9+7))
