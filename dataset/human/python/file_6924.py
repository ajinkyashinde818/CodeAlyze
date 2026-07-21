from collections import deque
import sys
input = sys.stdin.readline

s = deque(input().rstrip())

sw = True

nq = int(input().rstrip())
for _ in range(nq):
    query = input().rstrip()
    if query[0] == '1':
        sw = (sw == False)
    else:
        c = query[4]
        if (query[2] == '1') == sw: 
            s.appendleft(c)
        else:
            s.append(c)
if sw:
    print("".join(s))
else:
    print("".join(reversed(s)))
