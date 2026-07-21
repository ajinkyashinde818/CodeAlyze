from collections import deque

S = deque(input())
Q = int(input())
Queries = [input().split() for _ in range(Q)]

need_reverse = False

for q in Queries:
    if q[0] == "1":
        need_reverse = not need_reverse
    else:
        if q[1] == "1":
            if not need_reverse:
                S.appendleft(q[2])
            else:
                S.append(q[2])
        else:
            if not need_reverse:
                S.append(q[2])
            else:
                S.appendleft(q[2])

S = "".join(S)
print(S if not need_reverse else S[::-1])
