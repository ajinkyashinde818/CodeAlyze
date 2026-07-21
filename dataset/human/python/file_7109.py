s=list(input())
n=int(input())
from collections import deque
d=deque(s)
cnt=0
for i in range(n):
    a=list(input().split())
    if len(a)==1:
        cnt+=1
    else:
        if cnt%2==0:
            if a[1]=="1":
                d.appendleft(a[2])
            else:
                d.append(a[2])
        else:
            if a[1]=="2":
                d.appendleft(a[2])
            else:
                d.append(a[2])
if cnt%2==1:
    d=list(d)
    d=d[::-1]
    print("".join(d))
else:
    print("".join(d))
