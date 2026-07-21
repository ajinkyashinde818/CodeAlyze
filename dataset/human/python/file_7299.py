from collections import deque

S = str(input())
Q = int(input())

d = deque(list(S))

rev = False

for q in range(Q):
    query = list(map(str, input().split()))
    if int(query[0]) == 1:
        if rev:
            rev = False
        else:
            rev = True
    else:
        if int(query[1]) == 1:
            if not rev:
                d.appendleft(query[2])
            else:
                d.append(query[2])
        else:
            if not rev:
                d.append(query[2])
            else:
                d.appendleft(query[2])

if rev:
    print(''.join(d)[::-1])
else:
    print(''.join(d))
