from collections import deque
s = deque(input())
Q = int(input())
forward = 0
for _ in range(Q):
    q = input()
    if q=='1':
        forward ^= 1
    else:
        _, f, c = q.split()
        if (int(f)-1)^forward==0:
            s.appendleft(c)
        else:
            s.append(c)
s = list(s)
if forward:
    for i in reversed(s):
        print(i, end='')
else:
    for i in s:
        print(i, end='')
print()
