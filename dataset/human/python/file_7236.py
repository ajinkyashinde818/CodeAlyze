from collections import deque

S = deque(input().strip())
q = int(input())

rev = False
for _ in range(q):
    query = input().split()
    if query[0] == '1':
        rev = not rev
    else:
        if (query[1] == '1') ^ rev:
            S.appendleft(query[2])
        else:
            S.append(query[2])
S = S if not rev else reversed(S)
print(*S, sep='')
