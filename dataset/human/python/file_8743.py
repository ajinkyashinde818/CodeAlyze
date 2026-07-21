import numpy as np

N,M=(int(x) for x in input().split())
A=list(map(int, input().split()))
A=np.array(A)
B=A[1:]-A[:-1]
b=max(B)
c=A[-1]-A[0]
if c > N/2:
    d=int(N-c)
else:
    d=c
e=max(b,d)
f=N-e

print(f)
