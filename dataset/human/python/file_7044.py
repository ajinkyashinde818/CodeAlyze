from collections import deque

S = input()
Q = int(input())

is_reversed = False

S = deque(S)

for _ in range(Q):
    q = input().split(" ")
    if q[0] == "1":
        is_reversed = not is_reversed
    else:
        if q[1] == "1":
            if is_reversed:
                S.append(q[2])
            else:
                S.appendleft(q[2])
        else:
            if is_reversed:
                S.appendleft(q[2])
            else:
                S.append(q[2])

S = list(S)
if is_reversed:
    S = ''.join(list(reversed(S)))
else:
    S = ''.join((S))

print(S)
