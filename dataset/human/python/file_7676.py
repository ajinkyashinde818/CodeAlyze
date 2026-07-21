import sys
from collections import deque

S = deque(sys.stdin.readline().rstrip())
Q = int(sys.stdin.readline().rstrip())
flip = False

for i in range(Q):
    Que = sys.stdin.readline().rstrip()
    if Que == "1":
        flip = not(flip)
    else:
        Query = Que.split()
        F = Query[1]
        if (F == "1") ^ flip:
            S.appendleft(Query[2])
        else:
            S.append(Query[2])
print("".join(S) if not flip else "".join(S)[::-1])
