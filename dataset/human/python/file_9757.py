n,k=map(int,input().split())
A=[0]+list(map(int,input().split()))
from collections import defaultdict

reached=defaultdict(int)
reached[1]=1
i=1
for j in range(1,n+1):
    if reached[A[i]]==0:
        reached[A[i]]=j+1
    else:
        t1=reached[A[i]]
        t2=j+1
        break
    i=A[i]
reached=dict(reached)
if k>t1-1:
    ama=(k-(t1-1))%(t2-t1)
    ans=[s for s,h in reached.items() if h==t1+ama]
else:
    ans=[s for s,h in reached.items() if h==k+1]
print(ans[0])
