from itertools import accumulate

K,N=map(int,input().split())
A=list(map(int,input().split()))

D=[0]*(N+1)
for i in range(N-1):
    D[i+1]=A[i+1]-A[i]
D[-1]=K-A[-1]+A[0]
D.extend(D[1:])
D=list(accumulate(D))

ans=float('inf')
for l in range(1,N+1):
    r=l+N-1
    ans=min(ans,abs(D[r]-D[l]))
print(ans)
