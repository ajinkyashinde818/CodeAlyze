import sys

def input():
  return sys.stdin.readline()


N,K = map(int,input().split())
A=list(map(int,input().split()))
P=[True]*N
P[0]=False
i,a=1,0
while 1:
  a+=1
  if P[A[i-1]-1]:
    P[A[i-1]-1]=False
    i=A[i-1]
  else:
    i=A[i-1]
    break
if a>=K:
  i=1
  for _ in range(K):
    i=A[i-1]
  print(i)
else:
  K-=a
  a,j=0,i
  while 1:
    a+=1
    if A[j-1]==i:
      break
    j=A[j-1]
  K%=a
  for _ in range(K):
    i=A[i-1]
  print(i)
