from collections import deque

s = deque(input())
q = int(input())

rev = False
for _ in range(q):
    query = list(input().split())
    t = query[0]
    if t == "1":
        rev = not rev
    else:
        f = int(query[1])
        c = query[2]
        if rev:
            f = 3 - f
        if f == 1:
            s.appendleft(c)
        else:
            s.append(c)
if rev:
    s.reverse()
print(''.join(s))
