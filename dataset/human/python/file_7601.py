from collections import deque


S = deque(list(input()))
Q = int(input())
f = True
for i in range(Q):
    query = input().split(' ')
    if len(query) == 1:
        f = not f
    else:
        if (query[1] == '1' and f) or (query[1] == '2' and not f):
            S.appendleft(query[2])
        else:
            S.append(query[2])
S = "".join(list(S))
if not f:
    S = S[::-1]
print(S)
