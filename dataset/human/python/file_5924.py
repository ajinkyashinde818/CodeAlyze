import numpy as np

N=int(input())
A=np.array(input().split(),dtype=np.int32)-1
B=np.array(input().split(),dtype=np.int32)
C=np.array(input().split(),dtype=np.int32)

s=0
for i in range(len(A)):
    key=A[i]
    s+=B[key]
    if(i+1<=len(A)-1):
        if(key+1==A[i+1]):
            s+=C[key]

print(s)
