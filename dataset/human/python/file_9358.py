def getans(v,K):
    k=0
    now=v
    while K>0:
        if K&1:
            now=doubling[k][now]
        K=K>>1
        k+=1
    return now

N,K=map(int,input().split())
A=list(map(int,input().split()))

doubling=[[-1]*N for i in range(61)]
for i in range(N):
    doubling[0][i]=A[i]-1
for k in range(1,61):
    for i in range(N):
        doubling[k][i]=doubling[k-1][doubling[k-1][i]]
print(getans(0,K)+1)
