import numpy as np
N=int(input())
A=np.array(list(map(int, input().split())))
B=np.array(list(map(int, input().split())))
C=np.array(list(map(int, input().split())))

a=0
for i in range(N-1):
    if A[i]==A[i+1]-1:
        a+=C[A[i]-1]
print(np.sum(B)+a)
