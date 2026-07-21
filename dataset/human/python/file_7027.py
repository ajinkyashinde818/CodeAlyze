from collections import deque

S, inv = deque(input()), False
Q = int(input())
for _ in range(Q):
    q = input().split()
    if len(q) == 1:
        inv = not inv
        continue
    F, C = q[1], q[2]
    if (F == '1') ^ inv:
        S.appendleft(C)
    else:
        S.append(C)
print(''.join(S)[::-1] if inv else ''.join(S))
