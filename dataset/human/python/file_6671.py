from collections import deque

S = deque(input())
rev = False

Q = int(input())

for _ in range(Q):
    i_q = list(input().split())
    if i_q[0] == "1":
        rev = not rev
    else:
        appendtop = False
        if not rev and i_q[1] == "1":
            appendtop = True
        elif rev and i_q[1] == "2":
            appendtop = True

        if appendtop:
            S.appendleft(i_q[2])
        else:
            S.append(i_q[2])

if rev:
    while len(S) > 0:
        print(S.pop(), end="")
else:
    while len(S) > 0:
        print(S.popleft(), end="")

print()
