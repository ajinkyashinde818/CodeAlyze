from collections import deque

S = list(input())
Q = int(input())
d = deque(S)
flag = -1
for _ in range(Q):
    q = list(input().split())
    if q[0] == '1':
        flag *= -1
    else:
        f = int(q[1])
        c = q[2]
        if flag == -1 and f == 1 or flag == 1 and f == 2:
            d.appendleft(c)
        else:
            d.append(c)
d = list(d)
if flag == 1:
    d = d[::-1]

print(''.join(d))
