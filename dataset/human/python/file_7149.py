from collections import deque

s = input()

r = False
d = deque()
d.extend(list(s))

q = int(input())
for i in range(q):
    t = input()
    if t == "1":
        r = not r
    else:
        t, f, c = list(t.split())
        f = False if f=="1" else True

        if r == f:
            d.appendleft(c)
        else:
            d.append(c)

if r:
    d.reverse()

print("".join(d))
