from collections import deque

s=deque(input())
n=int(input())
r=False
for i in range(n):
    q=input()
    if q[0]=="1":
        r= not r
    else:
        t,f,c=map(str,q.split())
        if f=="1":
            if r==False:
                s.appendleft(c)
            else:
                s.append(c)
        else:
            if r==True:
                s.appendleft(c)
            else:
                s.append(c)
s=list(s)
if r==True:
    s=s[::-1]
print(*s,sep="")
