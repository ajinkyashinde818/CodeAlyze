import numpy as np
K,N=map(int, input().split())
A=list(map(int, input().split()))
K,N=int(K),int(N)
b=[]
for i in range(0,N-1):
    b.append(A[i+1]-A[i])
b.append(A[0]+K-A[N-1])
c=np.sum(b)
print(c-max(b))
