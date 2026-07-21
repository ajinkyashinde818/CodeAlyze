N,M=map(int,input().split())
from collections import defaultdict

d1=defaultdict(int)
d2=defaultdict(int)

for _ in range(M):
    a,b=map(int,input().split())
    if a==1:
        d1[b]=1
        if d2[b]==1:
            print('POSSIBLE')
            exit()
    if b==N:
        d2[a]=1
        if d1[a]==1:
            print('POSSIBLE')
            exit()
print('IMPOSSIBLE')
