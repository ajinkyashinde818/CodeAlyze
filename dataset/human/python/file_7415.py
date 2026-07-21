from collections import deque

dq = deque(list(input()))

Q = int(input())

reverse_count = 0

for i in range(Q):
    query = input().split()
    if query[0] == "1":
        reverse_count = 1 - reverse_count
    else:
        F = query[1]
        C = query[2]
        if F == "1":
            if reverse_count == 0:
                dq.appendleft(C)
            else:
                dq.append(C)
        else:
            if reverse_count == 0:
                dq.append(C)
            else:
                dq.appendleft(C)

if reverse_count == 0:
    print("".join(dq))
else:
    print("".join(reversed(dq)))
