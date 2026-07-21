from collections import deque

S = deque(input())
Q = int(input())
rev = False
for _ in range(Q):
    q = input().split()
    if q[0] == '1':
        rev = not rev
    else:
        if q[1] == '1':
            if rev:
                S.append(q[2])
            else:
                S.appendleft(q[2])
        else:
            if rev:
                S.appendleft(q[2])
            else:
                S.append(q[2])
if rev:
    S.reverse()

print(''.join(S))
