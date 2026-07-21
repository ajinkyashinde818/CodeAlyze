import sys
from collections import deque
s = list(input())
q = int(input())
h = deque()
h.extend(s)

rev = False
for _ in range(q):
    que = sys.stdin.readline().split()
    if que[0] == '1':
        if rev:
            rev = False
        else:
            rev = True
    elif que[1] == '1':
        if rev:
            h.append(que[2])
        else:
            h.appendleft(que[2])
    else:
        if rev:
            h.appendleft(que[2])
        else:
            h.append(que[2])
if rev:
    print(''.join(list(h)[::-1]))
else:
    print(''.join(list(h)))
