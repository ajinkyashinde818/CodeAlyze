from sys import stdin
nii=lambda:map(int,stdin.readline().split())
lnii=lambda:list(map(int,stdin.readline().split()))

n=int(input())
a=lnii()
b=lnii()
c=lnii()

ans=0
for i in range(n):
  ans+=b[a[i]-1]
  if i<n-1 and a[i]+1==a[i+1]:
    ans+=c[a[i]-1]

print(ans)
