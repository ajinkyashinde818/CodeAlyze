import numpy as np

K,N=map(int,input().split())
A=np.zeros(N)
A=list(map(int, input().split()))
dif=np.zeros(N)

for i in range(N-1):
    dif[i]=A[i+1]-A[i]

dif[N-1]=K-A[N-1]+A[0]

print(int(K-np.max(dif)))
