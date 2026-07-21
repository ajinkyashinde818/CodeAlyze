import collections
import numpy as np
import sys
import copy

N,K=map(int,input().split())
A=list(map(int,input().split()))
for i in range(N):
    A[i]-=1
B=[0]
visited=[0]*N
visited[0]=1
Flag=True
for i in range(0,N*2):
    next=A[B[i]]
    if visited[next]==0:
        B.append(next)
        visited[next]=1
    else:
        C=B[B.index(next):]
        num=B.index(next)
        break
#print(C)
if K>num:
    Ans=(K-num)%len(C)
    print(C[Ans]+1)
else:
    print(B[K]+1)
