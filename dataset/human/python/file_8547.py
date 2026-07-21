import sys
input=lambda: sys.stdin.readline().rstrip()
k,n=map(int,input().split())
A=[int(i) for i in input().split()]
ans=k-(k-A[-1]+A[0])
for i in range(n-1):
  ans=min(ans,k-A[i+1]+A[i])
print(ans)
