import numpy as np

K,N=list(map(int, input().split()))

A=list(map(int, input().split()))


A=np.array(A)

lin=np.array(A[:-1])
le=np.array(A[1:])

length=abs(lin-le)

rem=abs(K-A[-1]+A[0])

A=np.append(length,rem)

M=np.max(A)

print(K-M)
