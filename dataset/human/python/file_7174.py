from collections import deque
s=deque(input())
q=int(input())
rev=0
for i in range(q):
    p=list(map(str,input().split()))
    if p[0]=="1":
        rev^=1
    else:
        z,f,c=p
        if f=="1":
            if rev:
                s.append(c)
            else:
                s.appendleft(c)
        else:
            if rev:
                s.appendleft(c)
            else:
                s.append(c)
if rev:
    s=list(s)[::-1]
else:
    s=list(s)
print("".join(s))
