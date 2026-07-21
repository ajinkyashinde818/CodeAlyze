s = list(str(input()))
q = int(input())

from collections import deque
d = deque(s)
REVERSE = False

for _ in range(q):
    X = input().split()
    if X[0] == '1':
        REVERSE = not REVERSE
    else:
        if X[1] == '1' and not REVERSE:
            d.appendleft(X[2])
        elif X[1] == '2' and not REVERSE:
            d.append(X[2])
        elif X[1] == '1' and REVERSE:
            d.append(X[2])
        elif X[1] == '2' and REVERSE:
            d.appendleft(X[2])

if REVERSE:
    d.reverse()

print(*d, sep='')
