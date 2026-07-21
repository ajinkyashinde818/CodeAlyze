from operator import itemgetter
import sys
sys.setrecursionlimit(1000000)
ans=0

n=int(input())
a=[]
b=[]
c=0
for i in input().split():
    x=int(i)
    if x<0:
        c+=1
    a.append(x)
    b.append(abs(x))

b.sort()
ans=sum(b[1:])
if c%2==1:
    ans+=-b[0]
else:
    ans+=b[0]
print(ans)
