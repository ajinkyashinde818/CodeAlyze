import sys
input = sys.stdin.readline

n=int(input())
A=[int(i) for i in input().split()]
if sum(A)%(n*(n+1)//2)!=0:
  print("NO")
else:
  k=sum(A)//(n*(n+1)//2)
  AA=[0]*n
  for i in range(n):
    if i==n-1:
      AA[i]=A[0]-A[-1]-k
    else:
      AA[i]=A[i+1]-A[i]-k
  ans="YES"
  for i in range(n):
    if AA[i]>0 or AA[i]%n!=0:
      ans="NO"
  print(ans)
