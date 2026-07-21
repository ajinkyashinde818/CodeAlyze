import sys
a,b=map(int,input().split())
c=list(map(int,input().split()))
c.sort()
d=[0]*1000000
for i in range(b-1):
  d[i]+=abs(c[i]-c[i+1])
  

d.append(a-(c[-1]-c[0]))

print(a-max(d))
