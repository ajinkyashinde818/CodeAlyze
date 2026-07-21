import collections
from collections import deque

s= input()
n=int(input())
q= [list(input().split()) for i in range(n)]

s=deque(s)
flag=True
for i in range(n):
    if q[i][0]==str(1):
        if flag:
            flag=False
        else:
            flag=True
    else:
        if q[i][1]==str(1):
            if flag:
                s.appendleft(q[i][2])
            else:
                s.append(q[i][2])
        if q[i][1]==str(2):
            if flag:
                s.append(q[i][2])
            else:
                s.appendleft(q[i][2])

if not flag:
    s.reverse()
print(''.join(s))
