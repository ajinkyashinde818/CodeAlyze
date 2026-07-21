from collections import Counter
n=int(input())
a=list(map(int,input().split()))
b=list(map(int,input().split()))
ca=Counter(a)
cb=Counter(b)
for k in cb:
    if k in ca:
        if cb[k]+ca[k]>n:
            print('No')
            exit()
ans=b.copy()
ans.reverse()
ng=set(())
ok=[]
for i in range(n):
    if a[i]==ans[i]:
        ng.add(i)
    else:
        ok.append(i)
from random import randint
if ng:
    for x in ng:
        y=ok[randint(0,len(ok)-1)]
        while ans[x]==a[y] or ans[y]==a[x]:
            y=ok[randint(0,len(ok)-1)]
        ans[x],ans[y]=ans[y],ans[x]
        ok.append(x)
print('Yes')
print(*ans,sep=' ')
