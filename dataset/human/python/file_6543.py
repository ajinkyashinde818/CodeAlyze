from collections import deque

S=list(input())
Q=int(input())
Sq=deque(S)

flag=1
for _ in range(Q):
    q=input().split()
    if q[0]=='1':
        flag*=-1
        continue
    if (q[1]=='1' and flag==-1) or (q[1]=='2' and flag==1):
        Sq.append(q[2])
    else:
        Sq.appendleft(q[2])
if flag==1:
    print(''.join(Sq))
else:
    Sq.reverse()
    print(''.join(Sq))
