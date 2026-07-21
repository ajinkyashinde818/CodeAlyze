from collections import deque
S=input()
d=deque(S)
rev=False
Q=int(input())
for i in range(Q):
    Que=input().split()
    if(Que[0]=='1'):
        rev=not rev
    else:
        if(Que[1]=='1'):
            if(not rev):
                d.appendleft(Que[2])
            else:
                d.append(Que[2])
        else:
            if(not rev):
                d.append(Que[2])
            else:
                d.appendleft(Que[2])
d=d if not rev else reversed(d)
print(*d,sep='')
