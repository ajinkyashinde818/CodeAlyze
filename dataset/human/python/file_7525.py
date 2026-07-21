import sys
from collections import deque
S = deque(input())
Q = int(input())

reverse = False
for _ in range(Q):
    q = sys.stdin.readline()
    if q[0] == "1":
        reverse = not reverse
    else:
        _, f, c = q.split()
        if f == "1":
            if reverse:
                S.append(c)
            else:
                S.appendleft(c)
        else:
            if reverse:
                S.appendleft(c)
            else:
                S.append(c)
if reverse:
    S.reverse()
ans = "".join(S)
print(ans)
