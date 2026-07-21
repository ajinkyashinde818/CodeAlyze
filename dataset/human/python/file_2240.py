import sys
import math
d,g=map(int,input().split())
p=[]
c=[]
s=[]
count=0
for i in range(d):
    pi,ci=map(int,input().split())
    p.append(pi)
    c.append(ci)
    s.append((i+1)*100*pi+ci)

l=2**d
count=10**6*d
for i in range(l):
    buf=g
    x=0
    n=0
    for j in range(d):
        if i & 1 ==1:
            x+=p[j]
            buf-=s[j]
        else:
            n=j
        i=i>>1
    if buf>=0:
        y=math.ceil(buf/((n+1)*100))
        if y>p[n]:
            continue
        x=x+y
    count=min(count,x)
print(count)
