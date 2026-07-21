from collections import deque

S = deque(input())
Q = int(input())

d = 1
c = 1
for i in range(Q):
    que = list(input().split())
    if que[0] == str(1):
        d += c
        c *= -1
    else:
        if (int(que[1]) ^ d) == 0:
            S.appendleft(que[2])
        else:
            S.append(que[2])

print(''.join(S) if d == 1 else ''.join(S)[::-1])
