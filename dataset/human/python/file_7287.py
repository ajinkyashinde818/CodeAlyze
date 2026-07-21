from collections import deque

S = deque(input())
Q = int(input())

reversing = False

for i in range(Q):
    query = list(input().split())
    if query[0] == '1':
        reversing = not reversing
    else:
        if query[1] == '1':
            if not reversing:
                S.appendleft(query[2])
            else:
                S.append(query[2])
        else:
            if reversing:
                S.appendleft(query[2])
            else:
                S.append(query[2])

print(''.join(S)) if not reversing else print(''.join(reversed(S)))
