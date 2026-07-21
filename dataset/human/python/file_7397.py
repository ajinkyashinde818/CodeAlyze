from collections import deque
s = input()
s = deque([i for i in s])
q = int(input())
r = False
for _ in range(q):
    qu = input()
    if qu == "1":
        r = not r
    else:
        _, f, c = [i for i in qu.split()]
        if (f != "1") == r:
            s.appendleft(c)
        else:
            s.append(c)

s = "".join(s)
if r:
    s = reversed(s)
print("".join(s))
