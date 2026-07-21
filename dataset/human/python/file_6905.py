from collections import deque

s=input()
q=int(input())
d=deque()
d.append(s)
m=1
for i in range (q):
    a=list(input().split())
    if a[0]=="1":
        m=m*(-1)
    else:
        if m==1:
            if a[1]=="1":
                d.appendleft(a[2])
            else:
                d.append(a[2])
        else:
            if a[1]=="2":
                d.appendleft(a[2])
            else:
                d.append(a[2])
s="".join(d)


print(s[::m])
