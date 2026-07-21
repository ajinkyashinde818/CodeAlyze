import sys
import numpy as np
N,M=map(int,input().split())
A=np.zeros((N,N))
B=np.zeros((M,M))
for i in range(N):
    temp=input()
    temp=temp.replace('.',"0")
    temp=temp.replace('#',"1")
    A[i] = list(map(int,list(temp)))
for i in range(M):
    temp=input()
    temp=temp.replace('.',"0")
    temp=temp.replace('#',"1")
    B[i] = list(map(int,list(temp)))

for i in range(N-M+1):
    for j in range(N-M+1):
        if np.all(B == A[i:i+M,j:j+M]):
            print("Yes")
            sys.exit()
else:
    print("No")
