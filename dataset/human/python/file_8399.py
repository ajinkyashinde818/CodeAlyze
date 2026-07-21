import numpy as np

K,N=map(int,input().split())
A=list(map(int,input().split()))
A.sort()
x=np.array(A[1:])
y=np.array(A[:-1])
B=x-y
C=B.tolist()
C.append(K+A[0]-A[N-1])
print(K-int(max(C)))
