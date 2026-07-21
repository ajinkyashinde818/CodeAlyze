import sys
fastinput=sys.stdin.readline
N,M=map(int,fastinput().split())
first=[False]*N
second=[False]*N
for _ in range(M):
    i,j=[int(k) for k in fastinput().split()]
    if i==1:
        first[j-1]=True
    if j==N:
        second[i-1]=True
if any([(first[a] and second[a]) for a in range(N)]):
    print("POSSIBLE")
else:print("IMPOSSIBLE")
