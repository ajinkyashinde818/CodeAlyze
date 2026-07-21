s = input()
from collections import deque
d = deque()
for i in s:
    d.append(i)
mode = 0
Q = int(input())
for _ in range(Q):
    q = input()
    if q[0]=='1':
        mode+=1
        mode%=2
    else:
        t,f,c = q.split()
        f = int(f)
        if (f+mode)%2==1:
            d.appendleft(c)
        else:
            d.append(c)
if mode==1:
    while(len(d)):
        print(d.pop(),end='')
else:
    while(len(d)):
        print(d.popleft(),end='')
