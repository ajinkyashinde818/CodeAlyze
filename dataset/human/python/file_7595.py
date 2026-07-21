from collections import deque

S = deque(input())
Q = int(input())
is_reversed = False
for _ in range(Q):
    q = input().split()
    if q[0] == "1":
        is_reversed = not is_reversed
    else:
        f = int(q[1]) - 1
        if is_reversed:
            f ^= 1
        c = q[2]
        if f:
            S.append(c)
        else:
            S.appendleft(c)
if is_reversed:
    S = reversed(S)
print(*S, sep="")
