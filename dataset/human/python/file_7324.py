s=list(input())
from collections import deque
l=deque(s)
q=int(input())
m=1
for _ in range(q):
    x=list(input().split())
    if x[0]=="1":
        m*=-1
    else:
        f,c=x[1],x[2]
        f=int(f)
        if f==1:
            if m==1:
                l.appendleft(c)
            else:
                l.append(c)
        else:
            if m==1:
                l.append(c)
            else:
                l.appendleft(c)
if m==1:
    print("".join(l))
else:
    l.reverse()
    print("".join(l))
