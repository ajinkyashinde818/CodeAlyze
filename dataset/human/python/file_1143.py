import sys,itertools,collections,bisect
from collections import deque,Counter,defaultdict
from heapq import heappush,heappop,heapify
read=sys.stdin.readline
sys.setrecursionlimit(10**6)

N=int(input())
A=list(map(int,input().split()))
B=list(map(int,input().split()))
cA,cB=Counter(A),Counter(B)
for i in range(1,N+1):
    if cA.get(i,0)+cB.get(i,0)>N:
        print('No')
        exit()

C,D=[0]*(N+1),[0]*(N+1)
for i in range(1,N+1):
    C[i]=C[i-1]+cA.get(i,0)
    D[i]=D[i-1]+cB.get(i,0)


x,y=0,10**30
for i in range(1,N+1):
    x=max(x,C[i]-D[i-1])
    y=min(y,C[i-1]+N-D[i])

print('Yes')
print(*(B[N-y:]+B[:N-y]))
