from collections import deque

s = input()
q = int(input())

dq = deque(s)
rev = False
fcond = {"1": True, "2": False}
rcond = {True: False, False: True}
for i in range(q):
    t = input()
    if t.startswith("1"):
        rev = rcond[rev]
    elif t.startswith("2"):
        _, f, c = t.split()
        if fcond[f] is not rev:
            dq.appendleft(c)
        else:
            dq.append(c)
if rev:
    print("".join(reversed(dq)))
else:
    print("".join(dq))
