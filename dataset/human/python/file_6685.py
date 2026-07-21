from collections import deque

sc = iter(open(0).read().split())
ni = lambda: int(next(sc))
ns = lambda: next(sc)

S = ns()
S = deque(S)

rev = False
Q = ni()
for _ in range(Q):
    op = ni()
    if op == 1:
        rev = not rev
    else:
        F, C = ni(), ns()
        if F == 1:
            if rev:
                S.append(C)
            else:
                S.appendleft(C)
        else:
            if rev:
                S.appendleft(C)
            else:
                S.append(C)

print("".join(reversed(S) if rev else S))
