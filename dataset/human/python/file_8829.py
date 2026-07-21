import numpy as np

K,N=map(int,input().split())
A=list(map(int,input().split()))
A.sort()
last=A[0]+K-A[N-1]
dist=[]
for i in range(N-1):
    dist.append(A[i+1]-A[i])
dist.append(last)

print(K-max(dist))
