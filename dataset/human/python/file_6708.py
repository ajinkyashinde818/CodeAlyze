from collections import deque
s=deque(list(input()))
q=int(input())
r = False
for i in range(q):
    tmp = list(input().split(' '))
    if tmp[0]=='1':
        r = not r
    elif (not r and tmp[1]=='1') or (r and tmp[1] =='2'):
        s.appendleft(tmp[2])
    else:
        s.append(tmp[2])
if not r:
    for i in s:
        print(i,end='')
else:
    for i in reversed(s):
        print(i,end='')
