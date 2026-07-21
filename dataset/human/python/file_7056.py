from collections import deque
d = deque(list(input()))
rev = False
for _ in range(int(input())):
    q = list(input().split(" "))
    t = int(q[0])
    if t == 1:
        if rev:
            rev = False
        else:
            rev = True
    else:
        if int(q[1]) == 1:
            if rev:
                d.append(q[2])
            else:
                d.appendleft(q[2])
        elif int(q[1]) == 2:
            if rev:
                d.appendleft(q[2])
            else:
                d.append(q[2])
if rev:
    d.reverse()
for res in d:
    print(res, end="")
