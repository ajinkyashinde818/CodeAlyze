import sys
from pprint import pprint
from collections import deque

S = list(sys.stdin.readline().strip())
Q = int(sys.stdin.readline().strip())

q = deque(S)

n_rev = 0
for _ in range(Q):
    tmp = sys.stdin.readline().strip().split()
    if tmp[0] == "1":
        n_rev += 1
    else:
        f, c = tmp[1], tmp[2]
        if f == "1":
            if n_rev % 2 == 0:
                #S = c + S
                q.appendleft(c)
            else:
                #S = S + c
                q.append(c)
        else:
            if n_rev % 2 == 0:
                #S = S + c
                q.append(c)
            else:
                #S = c + S
                q.appendleft(c)

S = "".join(list(q))
if n_rev % 2 == 0:
    print(S)
else:
    print(S[::-1])
