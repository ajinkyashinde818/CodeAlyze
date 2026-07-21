from collections import deque

s = input()
q = int(input())

s = deque(s)

rev = 0
for _ in range(q):
    que = input()
    if que[0] == "1":
        rev ^= 1

    else:
        t, f, c = que.split()
        if rev:
            if f == "1":
                s.append(c)
            else:
                s.appendleft(c)

        else:
            if f == "1":
                s.appendleft(c)
            else:
                s.append(c)

s = list(s)
if rev:
    print(*s[::-1], sep="")
else:
    print(*s, sep="")
