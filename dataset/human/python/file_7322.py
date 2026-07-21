from collections import deque
s = deque(input())
q = int(input())
rev = False
for _ in range(q):
    que = input()
    if que == "1":
        rev = not rev
    else:
        f,c = que[2:].split()
        if (f == "1") ^ rev:
            s.appendleft(c)
        else:
            s.append(c)

if rev: s.reverse()

print("".join(s))
