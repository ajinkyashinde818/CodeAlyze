from collections import deque
S = input()
d = deque(S)
Q = int(input())
rev = False
for _ in range(Q):
    Q, *sub = input().split()
    if Q == "1":
        rev = not rev
    else:
        F, C = sub
        if F == "1":
            if rev:
                d.append(C)
            else:
                d.appendleft(C)
        else:
            if rev:
                d.appendleft(C)
            else:
                d.append(C)
if rev:
    d.reverse()
print("".join(list(d)))
