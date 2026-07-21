import sys
from collections import deque


reverse = 0
S = deque(list(input()))
q = int(input())

for query in sys.stdin:
    if query[0] == '1':
        reverse = 1 - reverse
        continue

    _, f, c = query.split()
    f = int(f)
    action = (reverse + f) % 2
    if action:
        S.appendleft(c)
    else:
        S.append(c)

if reverse:
    S.reverse()

print(''.join(S))
