from collections import deque

s = list(input())
d = deque(s)
forward = True
q = int(input())
for i in range(q):
    l = input().split()
    if len(l) == 1:
        forward = not forward
    else:
        pos = int(l[1])
        c = l[2]
        if pos == 1:
            if forward:
                d.appendleft(c)
            else:
                d.append(c)
        else:
            if forward:
                d.append(c)
            else:
                d.appendleft(c)

if forward == False:
    d.reverse()

print("".join(d))
