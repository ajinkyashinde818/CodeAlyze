N,K=map(int,input().split())
A=list(map(int,input().split()))
for i in range(N):
    A[i]-=1
ed=[]
d=set()
now=0
x=-1
while True:
    ed.append(now)
    d.add(now)
    ne=A[now]
    if ne in d:
        now=ne
        x=ne
        break
    else:
        now=ne
loop=[x]
now=x
while True:
    now=A[now]
    if now==x:
        break
    else:
        loop.append(now)
def ind(l,a):
    for i in range(len(l)):
        if a==l[i]:
            return i
dn=ind(ed,ne)
T=len(loop)
if K>=dn:
    ans=loop[(K-dn)%T]
    print(ans+1)
else:
    print(ed[K]+1)
