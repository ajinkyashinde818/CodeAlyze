import sys
from collections import deque

s = list(sys.stdin.readline().rstrip())
q = int(sys.stdin.readline())
head = 0
s = deque(s)

for _ in range(q):
    query = sys.stdin.readline().split()
    if len(query) == 1:
        head = 1 if head == 0 else 0
    elif (query[1] == '1' and head == 1) or (query[1] == '2' and head == 0):
        s.append(query[2])
    else:
        s.appendleft(query[2])

if head == 1:
    s.reverse()

print(''.join(s))
