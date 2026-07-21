from collections import deque
S = deque(list(input()))
Q = int(input())
rev = False
for i in range(Q):
    query = input()
    if query == "1":
        rev = not(rev)
    else:
        T,F,C = query.split()
        if rev:
            if F == "1":
                S.append(C)
            else:
                S.appendleft(C)
        else:
            if F == "1":
                S.appendleft(C)
            else:
                S.append(C)
if rev:
    print("".join(list(reversed(S))))
else:
    print("".join(S))
