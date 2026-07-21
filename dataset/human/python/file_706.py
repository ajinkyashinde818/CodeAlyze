from heapq import heappop,heappush
import sys
input = sys.stdin.readline
from math import sqrt
xs,ys,xt,yt=map(int,input().split())
N=int(input())
table=[[10**16]*(N+2) for i in range(N+2)]
L=[(xs,ys,0)]
for i in range(N):
    x,y,r=map(int,input().split())
    L.append((x,y,r))
L.append((xt,yt,0))
for i in range(N+2):
    for j in range(i+1,N+2):
        x,y,r=L[i]
        z,w,l=L[j]
        k=max(0,sqrt( abs(x-z)**2 + abs(y-w)**2   )-r-l )
        table[i][j]=k
        table[j][i]=k
H=[]
H.append((0,0))
visit=[0]*(N+2)
visit[0]=1
val=[10**16]*(N+2)
val[0]=0
#print(table)
while H:
    #print(H)
    cost,pt=heappop(H)
    if val[pt]<cost:
        continue
    if pt==N+1:
        print(val[pt])
        sys.exit()
    visit[pt]=1
    for j in range(N+2):
        if visit[j]==0 and j!=pt and val[j]>table[j][pt]+val[pt]:
            val[j] = table[j][pt] + val[pt]
            heappush(H,(val[j],j))
