import collections
n=int(input())
s=list(str(input()))
c=collections.Counter(s)

testlist=list(c.values())
ans=1

for i in range(len(testlist)):
    ans=ans*(testlist[i]+1)
    ans=ans%(10**9+7)
ans=ans-1

print(int(ans))
