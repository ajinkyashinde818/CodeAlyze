import sys
n=int(input())
s=list(input())
m=10**9+7
if s[0]=='W' or s[2*n-1]=='W':
  print(0)
  sys.exit()
side=[]
l=['L','R']
for i in range(2*n):
  if i==0:
    side.append('L')
  else:
    if s[i-1]==s[i]:
      side.append(l[(l.index(side[i-1])+1)%2])
    else:
      side.append(l[l.index(side[i-1])])
ctL=0;ctR=0;ans=1
for i in range(2*n):
  if side[i]=='L':
    ctL+=1
  else:
    ans=ans*(ctL-ctR)
    ans%=m
    ctR+=1
if ctL!=ctR:
  print(0)
  sys.exit()
for i in range(1,n+1):
  ans*=i
  ans%=m
print(ans)
