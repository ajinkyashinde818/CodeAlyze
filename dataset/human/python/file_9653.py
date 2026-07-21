import sys
n,k=map(int,input().split())
a=list(map(lambda x:int(x)-1,input().split()))

x=[-1]*n
x[0]=0
now=0

if k<=n:
    for _ in range(k):
        now=a[now]
    print(now+1)
    sys.exit()

for i in range(1,n+1):
    now=a[now]
    if x[now]==-1:
        x[now]=i
    else:
        k=(k-x[now])%(i-x[now])
        break
for i in range(k):
    now=a[now]
print(now+1)
