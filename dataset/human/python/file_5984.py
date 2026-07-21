import numpy as np
N=int(input())
A=np.array(list(map(int,input().split())))
B=list(map(int,input().split()))
C=np.array(list(map(int,input().split())))

sb=sum(B)
dC=np.diff(A)

sC=C[A[np.where(dC==1)[0]]-1].sum()
#print(sb, sC)
print(sb+sC)
