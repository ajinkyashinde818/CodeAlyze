import numpy as np

N,M=map(int, input().split())
A=[]
for i in range(N):
    a=list(input())
    A.append(a)
B=[]
for i in range(M):
    b=list(input())
    B.append(b)

A=np.array(A)
B=np.array(B)
ans="No"
for i in range(N):
    for j in range(N):
        if i+M<=N and j+M<=N:
            if (A[i:i+M, j:j+M]==B).all():
                ans="Yes"

print(ans)
