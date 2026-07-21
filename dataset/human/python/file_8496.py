import math
K,N=map(int,input().split())
A=list(map(int,input().split()))
A.append(A[0]+K)
maxi=0
max=0
dis=0
for i in range(len(A)-1):
    if A[i+1]-A[i]>max:
        max=A[i+1]-A[i]
        maxi=i
for i in range(0,maxi):
    dis+=A[i+1]-A[i]
for i in range(maxi+1,len(A)-1):
    dis+=A[i+1]-A[i]
print(dis)
