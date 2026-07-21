from collections import deque
s = deque(input().split())
q = int(input())
rev = False
for _ in range(q):
    qu = input()
    if qu == "1":
        rev = not rev
    else:
        _, f, c = qu.split()
        if (f != "1") == rev:
            s.appendleft(c)
        else:
            s.append(c)

s = "".join(s)
if rev:
    s = reversed(s)
print("".join(s))
