import io
import sys
import math

n=int(input())
ans=0
A=list(map(int,input().split()))
B=list(map(int,input().split()))
C=list(map(int,input().split()))

for i in range(n):
  ans+=B[i]
for j in range(n-1):
  if (A[j]+1)==A[j+1]:
    ans+=C[A[j]-1]
print(ans)
