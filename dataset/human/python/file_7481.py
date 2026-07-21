from collections import deque

S = deque(input())
Q = int(input())

rev = False

for _ in range(Q):
    T, F, C, *_ = input().split() + [None, None]

    if int(T) == 1:
        rev = not rev
    else:
        F = int(F)
        if rev:
            F = F % 2 + 1

    if F == 1:
        S.appendleft(C)
    else:
        S.append(C)

if rev:
    S.reverse()

print(*[x for x in S if x], sep='')
