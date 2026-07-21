from collections import deque
d = deque()
S = input()
for i in S:
    d.append(i)
Q = int(input())
f = True
for i in range(Q):
    t = input()
    if t == "1":
        f = bool(not f)
    else:
        _, F, C = (a for a in t.split())
        if f:
            if F == "1":
                d.appendleft(C)
            else:
                d.append(C)
        else:
            if F == "1":
                d.append(C)
            else:
                d.appendleft(C)
if not f:
    d.reverse()
print("".join(d))
