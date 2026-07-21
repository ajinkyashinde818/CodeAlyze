from collections import deque
S = deque(input())
Q = int(input())

p = 0

for i in range(Q):
    query = input().split()
    if query[0]=='1':
        p ^= 1
    else:
        f = int(query[1])-1
        c = query[2]
        if p:
            f ^= 1
        if f:
            S.append(c)
        else:
            S.appendleft(c)

if p:
    print(*reversed(S), sep='')
else:
    print(*S, sep='')
