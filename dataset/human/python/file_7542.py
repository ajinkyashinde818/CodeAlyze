import sys
from collections import deque
s = input()
q = int(input())
is_reverse = False
res = deque(list(s))
for i in range(q):
    query = [i for i in sys.stdin.readline().split()]
    if query[0] == "1":
        is_reverse = False if is_reverse else True
    else:
        if query[1] == "1":
            if is_reverse:
                res.append(query[2])
            else:
                res.appendleft(query[2])
        else:
            if is_reverse:
                res.appendleft(query[2])
            else:
                res.append(query[2])
if is_reverse:
    res.reverse()
    print("".join(res))
else:
    print("".join(res))
