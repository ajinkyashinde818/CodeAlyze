S = input()
Q = int(input())
queries = [list(map(str, input().split())) for _ in range(Q)]

from collections import deque
s = deque(S)

mode = True
for query in queries:
    if len(query) == 1:
        mode = False if mode else True
        continue
    f = int(query[1])
    c = query[2]
    if mode:
        if f == 1:
            s.appendleft(c)
        else:
            s.append(c)
    else:
        if f == 2:
            s.appendleft(c)
        else:
            s.append(c)

if mode:
    print(*s, sep='')
else:
    print(*list(s)[::-1], sep='')
