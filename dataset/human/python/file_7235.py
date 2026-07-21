from collections import deque
from sys import exit, stdin

S = deque(stdin.readline().rstrip())
Q = int(stdin.readline().rstrip())
query = [stdin.readline().rstrip().split() for _ in range(Q)]
front = 0

for q in query:
    if q[0] == '1':
        if front == 0:
            front = -1
        elif front == -1:
            front = 0
    elif q[0] == '2':
        if q[1] == '1':
            if front == 0:
                S.appendleft(q[2])
            elif front == -1:
                S.append(q[2])
        elif q[1] == '2':
            if front == 0:
                S.append(q[2])
            elif front == -1:
                S.appendleft(q[2])
if front == 0:
    print(''.join(S))
elif front == -1:
    S.reverse()
    print(''.join(S))
