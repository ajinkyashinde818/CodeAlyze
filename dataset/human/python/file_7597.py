from collections import deque
s = deque(input())
q = int(input())
rev = 0

for i in range(q):
    t = input()
    if rev == 0:
        if len(t) == 1:
            rev = 1
        else:
            if t[2] == "1":
                s.appendleft(t[4])
            else:
                s.append(t[4])
    else:
        if len(t) == 1:
            rev = 0
        else:
            if t[2] == "1":
                s.append(t[4])
            else:
                s.appendleft(t[4])

if rev == 1:
    s.reverse()
print(*s, sep="")
