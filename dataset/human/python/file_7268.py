from collections import deque
import sys
read = sys.stdin.readline

s = deque(read().rstrip())
q = int(read())

rev = 0
for _ in range(q):
    a = tuple(read().split())
    if a[0] == '1':
        rev ^= 1
    else:
        dir = rev ^ int(a[1]) - 1
        if dir == 0:
            s.appendleft(a[2])
        else:
            s.append(a[2])

if rev:
    print(''.join(s)[::-1])
else:
    print(''.join(s))
