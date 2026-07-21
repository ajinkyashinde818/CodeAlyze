import sys
n=int(input())
a=list(map(int,input().split()))
s=sum(a)
if s%(n*(n+1)//2)!=0:
  print('NO')
  sys.exit()
else:
  x=s//(n*(n+1)//2)
d=[]
for i in range(n-1):
  d.append(a[i+1]-a[i])
d.append(a[0]-a[n-1])
for i in range(n):
  d[i]-=x
  if d[i]%n!=0 or d[i]>0:
    print('NO')
    sys.exit()
print('YES')
