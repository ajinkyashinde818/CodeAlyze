import sys
from collections import deque

readline = sys.stdin.readline
s = deque(readline().strip())
n = int(readline())
q = sys.stdin.readlines()
reverse = False
for qi in q:
    if qi[0] == '1':
        reverse = not reverse
    else:
        c = qi[4]
        if qi[2] == '2':
            if reverse:
                s.appendleft(c)
            else:
                s.append(c)
        else:
            if reverse:
                s.append(c)
            else:
                s.appendleft(c)
if reverse:
    s = reversed(list(s))
print(''.join(s))
