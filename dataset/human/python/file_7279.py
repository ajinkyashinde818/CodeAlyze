from collections import deque

s = deque(input())
q = int(input())
rev = False

for _ in range(q):
    t = input()
    if t[0] == "2":
        _, f, c = t.split()
        if rev:
            if f == "2": s.appendleft(c)
            else: s.append(c)
        else:
            if f == "1": s.appendleft(c)
            else: s.append(c)
    else: rev = not rev

if rev: s.reverse()
print("".join(s))
