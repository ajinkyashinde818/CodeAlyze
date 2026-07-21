N,K=map(int,input().split())
A=list(map(int,input().split()))
from collections import defaultdict
d = defaultdict(int)
n=0
d[0]=1
i=2
while d[A[n]-1]==0:
  d[A[n]-1]+=i
  if i-1==K:
    print(A[n])
    exit(0)
  i+=1
  n=A[n]-1
K-=d[A[n]-1]-1
X=d[n]-d[A[n]-1]+1
n=A[n]-1
for i in range(K%X):
  n=A[n]-1
print(n+1)
