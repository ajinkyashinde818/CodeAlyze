import sys
n=int(input())
s=input()
MOD=10**9+7
if s[0]=='W' or s[-1]=='W':
  print(0)
  sys.exit()
a=[-1]*(2*n)
current=1
for i in range(2*n-1):
  a[i]=current
  if s[i]==s[i+1]:
    current=1-current
if current==1:
  print(0)
  sys.exit()
a[2*n-1]=0
if sum(a)!=n:
  print(0)
  sys.exit()
ans=1
current=0
for i in range(2*n):
  if a[i]==1:
    current+=1
  else:
    current-=1
  if current<0:
    print(0)
    sys.exit()
current=0
for i in range(2*n):
  if a[2*n-1-i]==0:
    current+=1
  else:
    current-=1
  if current<0:
    print(0)
    sys.exit()
current=0
for i in range(2*n):
  if a[2*n-1-i]==0:
    current+=1
  else:
    ans=(ans*current)%MOD
    current-=1
for i in range(1,n+1):
  ans=(ans*i)%MOD
print(ans)
