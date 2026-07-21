from collections import deque

S = deque(input())
Q = int(input())

flip = 0
for _ in range(Q):
    q = input().split()
    if q[0] == "1":
        flip += 1
        flip %= 2
    else:
        if (int(q[1]) - 1 + flip)%2 == 0:
            S.appendleft(q[2])
        else:
            S.append(q[2])

S = list(S)
if flip == 0:
    print(*S, sep="")
else:
    print(*S[::-1], sep="")
