from collections import deque

d = deque(input())
Q = int(input())

qs = [list(map(str, input().split())) for _ in range(Q)]

vector = True
for q in qs:
    if q[0] == "1":
        vector = not vector
    else:
        if q[1] == "1":
            if vector:
                d.appendleft(q[2])
            else:
                 d.append(q[2])
        else:
            if vector:
                d.append(q[2])
            else:
                 d.appendleft(q[2])

if not vector:
    d.reverse()

ans = ''.join(d)
print(ans)
