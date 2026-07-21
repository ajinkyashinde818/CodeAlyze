from collections import deque
s = deque(input())
q = int(input())
query = [list(input().replace(' ','')) for _ in range(q)]

r = False
for i in range(q):
    if r:
        if len(query[i]) == 1:
            r = False
        elif query[i][1] == '1':
            s.append(query[i][2])
        else:
            s.appendleft(query[i][2])
    else:
        if len(query[i]) == 1:
            r = True
        elif query[i][1] == '1':
            s.appendleft(query[i][2])
        else:
            s.append(query[i][2])

if r:
    s = reversed(s)
    t = ''.join(s)
    print(t)
else:
    t = ''.join(s)
    print(t)
