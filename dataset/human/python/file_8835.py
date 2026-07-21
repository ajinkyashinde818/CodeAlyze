import sys
readline=sys.stdin.readline

K,N=map(int,readline().split())
A=list(map(int,readline().split()))

maxdiff=K-(A[-1]-A[0])
for i in range(1,len(A)):
  if abs(A[i]-A[i-1])>maxdiff:
    maxdiff=abs(A[i]-A[i-1])
print(K-maxdiff)
