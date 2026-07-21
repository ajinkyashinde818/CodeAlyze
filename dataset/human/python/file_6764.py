import sys
from collections import deque
input = sys.stdin.readline

S = deque(input().strip())
Q = int(input())
flag = 0

for i in range(Q):
    q = input().split()
    if q[0] == '1':
        flag = 1 if not flag else 0
    elif q[0] == '2':
        if q[1] == '1':
            S.appendleft(q[2]) if not flag else S.append(q[2])
        elif q[1] == '2':
            S.append(q[2]) if not flag else S.appendleft(q[2])

print(''.join(S)) if not flag else print(''.join(reversed(S)))
