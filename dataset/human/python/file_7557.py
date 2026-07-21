from collections import deque
s = input()
q = int(input())

dq = deque(s)
rev = False

for _ in range(q):
    t = list(input().split())
    if t[0] == "1":
        rev = not rev
    elif t[0] == "2":
        f = t[1]
        c = t[2]
        if f == "1":
            if rev:
                dq.append(c)
            else:
                dq.appendleft(c)
        else:
            if rev:
                dq.appendleft(c)
            else:
                dq.append(c)
                
if rev:
    print("".join(list(dq)[::-1]))
else:
    print("".join(list(dq)))
