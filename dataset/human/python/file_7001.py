from collections import deque

S = deque(input())
q = int(input())

reverse = False
for _ in range(q):
    query = input().split()
    if query[0] == '1':
        reverse = not reverse
    else:#2
        if query[1] == '1':
            if reverse:
                S.append(query[2])
            else:
                S.appendleft(query[2])
        else:
            if reverse:
                S.appendleft(query[2])
            else:
                S.append(query[2])

if reverse:
    while S:
        print(S.pop(), end='')
else:
    while S:
        print(S.popleft(), end='')
