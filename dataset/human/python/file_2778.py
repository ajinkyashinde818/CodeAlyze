cost={(i,j):[] for i in range(51) for j in range(51)}
def dfs(nf,c,fr,to):
    if nf==to:
        cost[(fr,to)].append(c)
        return 0

    if to*2+1>nf:
        return 0

    for i in range(1,nf+1):
        dfs(nf%i,c+2**i,fr,to)


for i in range(1,51):
    for j in range(51):
        dfs(i,0,i,j)
        cost[(i,j)].sort()

N=int(input())
a=list(map(int,input().split()))
b=list(map(int,input().split()))

for i in range(51):
    cost[(i,i)].append(0)

for i in range(N):
    if not cost[(a[i],b[i])]:
        print(-1)
        exit()

ans=0
k=50
while k>0:
    check=False
    for i in range(N):
        test=cost[(a[i],b[i])][0]
        if test>>k &1==1:
            check=True

    if check:
        ans+=2**k
        for i in range(N):
            for j in range(len(cost[(a[i],b[i])])):
                c=cost[(a[i],b[i])][j]
                if c>>k &1==1:
                    cost[(a[i],b[i])][j]-=2**k
            cost[(a[i],b[i])].sort()
    k-=1

print(ans)
