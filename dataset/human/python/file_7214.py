s = input()
q = int(input())

u = []
for i in range(q):
    u.append(list(map(str,input().split())))

from collections import deque
l = deque([])
r = deque([])

x = 1
for i in range(q):
    if int(u[i][0]) == 1:
        x = x*(-1)
    else:
        if int(u[i][1])*x == 1 or int(u[i][1])*x == -2:
            l.append(u[i][2])
        else:
            r.append(u[i][2])
if x == 1:
    print(''.join(l)[::-1]+s[::x]+''.join(r))
else:
    print(''.join(r)[::-1]+s[::x]+''.join(l))
