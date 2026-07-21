from sys import stdin
from collections import deque

s = deque(x for x in stdin.readline().rstrip())
q = int(stdin.readline().rstrip())

direction = 1

for i in range(q):
    query = stdin.readline().rstrip().split()
    if len(query) == 1:
        direction *= -1
    else:
        if ((query[1] == '1') and (direction == 1)) or ((query[1] == '2') and (direction == -1)):
            s.appendleft(query[2])
        else:
            s.append(query[2])

sl = list(s)
if direction == 1:
    print(''.join(sl))
else:
    print(''.join(sl[::-1]))
