s = input()
n = int(input())
que = []
for i in range(n):
    que.append(input())
from collections import deque
d=deque(s)
rev=False
for q in que:
    if q == "1":
        rev= not rev
    else:
        t,f,c = q.split()
        HorT=rev
        if f=="1":
            HorT=not rev
        if HorT:
            d.appendleft(c)
        else:
            d.append(c)
if rev:
    d.reverse()
print(*d,sep="")
