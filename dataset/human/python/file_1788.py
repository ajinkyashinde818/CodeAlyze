N,M=map(int,input().split())
A=[input() for i in range(N)]
B=[input() for i in range(M)]

def check(w,h):
    if w+M>N or h+M>N:
        return False
    List=[A[j][w:w+M] for j in range(h,h+M)]
    return (List==B)

ans=0
for i in range(N):
    for k in range(N):
        ans+=check(i,k)

print(['No','Yes'][ans>=1])
