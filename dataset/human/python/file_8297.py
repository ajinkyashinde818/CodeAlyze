n=int(input())
A=list(map(int,input().split()))
import numpy as np
nwa=n*(n+1)//2
if sum(A)%nwa!=0 : print("NO");exit()
k= sum(A)//nwa 


D=[0]*n
D[0]=A[0]-A[-1]
for i in range(n-1):
    D[i+1]= A[i+1]-A[i]

# print(D)
D=[i-k for i in D]
for i in D:
    if i>0:print("NO");exit()
    if i==0:continue
    if abs(i)%n!=0: print("NO");exit()
else:
    print("YES")
