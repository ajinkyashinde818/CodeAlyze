from collections import deque
s = input().replace("\n", "")
s = deque(list(s))
q = int(input())
r = 0
for _ in range(q):
    t = input().split()
    if t[0] == "1":
        r = (r + 1) % 2
    else :
        if t[1] == "1":
            if r == 0:
                s.appendleft(t[2])
            else:
                s.append(t[2])
        else:
            if r == 0:
                s.append(t[2])
            else:
                s.appendleft(t[2])

if r == 0:
    print("".join(s))
else:
    print("".join(list(s)[::-1]))
