from collections import deque

s=deque(list(input()))
q=int(input())

right=True
rev=False
for i in range(q):
    t=input().split()
    if t[0]=="1":
        right=not right
    if t[0]=="2":
        f=int(t[1])
        c=t[2]
        if f==1:rev=True
        else:rev=False

        if right^rev:
            s.append(c)
        else:
            s.appendleft(c)

if not right:
    s.reverse()
ans="".join(list(s))
print(ans)
