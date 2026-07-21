from sys import stdin

n = int(stdin.readline().rstrip())
an = list(map(int, input().split()))

m = []
p = []
z = 0

for i in range(n):
  if(an[i]<0):
    m.append(an[i])
  if(an[i]>0):
    p.append(an[i])
  if(an[i]==0):
    z=1

if ( z==1 ):
  ans = sum(p) - sum(m)
elif ( len(m) == 0):
    ans = sum(p)
else:
  if ( len(p) == 0):
    if ( len(m)%2 == 0):
      ans = - sum(m)
    else:
        minm = -max(m)
        ans = -sum(m) - (minm*2)
  else:
    if ( len(m)%2 == 0):
      ans = sum(p) - sum(m)
    else:
      minm = 0
      if ( min(p) < (-max(m)) ):
        minm = min(p)
      else:
        minm = -max(m)
      ans  = sum(p) - sum(m) - (minm*2)

print(ans)
