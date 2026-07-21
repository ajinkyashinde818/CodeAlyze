from collections import deque
S = list(input())
S = deque(S)
Q = int(input())
c = 0
for _ in range(Q):
    q = list(input().split())
    if int(q[0]) == 1:
        if c == 0:
            c = 1
        else:
            c = 0
    else:
        if c == 0:
            if int(q[1]) == 1:
                S.appendleft(q[2])
            else:
                S.append(q[2])
        else:
            if int(q[1]) == 2:
                S.appendleft(q[2])
            else:
                S.append(q[2])
S = list(S)
if c == 0:
    print("".join(S))
else:
    S = S[::-1]
    print("".join(S))
