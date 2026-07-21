from collections import defaultdict
N,K=map(int,input().strip().split())
A=[0]+list(map(int,input().strip().split()))

G=defaultdict(list)
prev=1

visited=set()
visited.add(1)

next=A[1]
while(not next in visited):
    G[prev].append(next)
    prev=next
    visited.add(next)
    next=A[next]
G[prev].append(next)
#loop starts from next
#calculate length = number of nodes in loop from next to prev

origin=next
next=G[origin][0]
cnt=0 ##length of loop
while(next!=origin):
    cnt+=1
    next=G[next][0]
##get Distance require to travel from town 1 to origin.
cnt+=1
origin1=1
next=G[1][0]
dist=0
while(next!=origin):
    dist+=1
    next=G[next][0]
dist+=1
if K<dist:
    cnt =0
    origin=1
    next=origin
    while(cnt!=K):
        cnt+=1
        next=G[next][0]
    print(next)
else:
    K=K-dist
    N=K%cnt
#travel N nodes from origin i.e start of the loop
    cnt=0
    next=origin
    while(cnt!=N):
        cnt+=1
        next=G[next][0]
    print(next)
