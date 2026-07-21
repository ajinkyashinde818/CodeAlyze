import sys
stdin=sys.stdin

ns = lambda:stdin.readline().rstrip()
ni = lambda:int(stdin.readline().rstrip())
nm = lambda:map(int,stdin.readline().split())
nl = lambda:list(map(int,stdin.readline().split()))

N,K=nm()
A=nl()

D=60
MAX_N=2000005
to=[[0]*MAX_N for i in range(D)]

to[0][1:N+1]=A

for i in range(D-1):
    for j in range(1,N+1):
        to[i+1][j]=to[i][to[i][j]]

v=1
for i in range(D-1,-1,-1):
    l = 1<<i
    if(l<=K):
        v=to[i][v]
        K-=l

print(v)
