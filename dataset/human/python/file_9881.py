N,K=map(int,input().split())
A=list(map(int,input().split()))
def warp(x,k):
    a=x
    for i in range(k):
        a=A[a-1]
    return a
count=[-1 for i in range(N)]
x=1
count[0]=0
time=0
if N>=K:
    print(warp(1,K))
else:
    for i in range(1,N+1):
        x=warp(x,1)
        if count[x-1]==-1:
            count[x-1]=i
        else:
            time=i-count[x-1]
            break;
    print(warp(1,count[x-1]+(K-count[x-1])%time))
