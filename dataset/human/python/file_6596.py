from collections import deque

s = deque(input())
n = int(input())

memo = 0
for i in range(n):
    q = list(input().split())
    if q[0] == '1':
        if  memo == 0: memo = 1
        else: memo = 0
    else:
        if memo == 0:
            if q[1] == '1': s.appendleft(q[2])
            else: s.append(q[2])
        else:
            if q[1] == '1': s.append(q[2])
            else: s.appendleft(q[2])

if memo == 0: print(''.join(s))
else: print(''.join(list(s)[::-1]))
