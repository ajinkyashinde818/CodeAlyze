import sys
from collections import deque
s = input()
q = int(input())
dq = deque(s)
rev = False
for i in range(q):
    t = input().split()
    if t[0] == "1":
        rev = not rev
    else:
        if t[1] == "1":
            if rev:
                dq.append(t[2])
            else:
                dq.appendleft(t[2])
        else:
            if rev:
                dq.appendleft(t[2])
            else:
                dq.append(t[2])
s = "".join(list(dq))
if rev:
    print(s[::-1])
else:
    print(s)
