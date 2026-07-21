from collections import deque

S = list(input())
Q = int(input())

S = deque(S)
rev = 1
for _ in range(Q):
    query = input()
    if len(query) == 1:
        rev *= -1
    else:
        T, F, C = query.split()
        if rev == 1:
            if F == "1":
                S.appendleft(C)
            else:
                S.append(C)
        else:
            if F == "1":
                S.append(C)
            else:
                S.appendleft(C)

if rev == -1:
    S = reversed(S)

print("".join(S))
