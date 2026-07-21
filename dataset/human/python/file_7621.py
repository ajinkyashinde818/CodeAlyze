from collections import deque

s = deque(list(input()))
n = int(input())
f = True

for i in range(n):
    a = input()
    if a == "1":
        f = not f
    else:
        b,c,d = a.split()
        if f:
            if c == "1":
                s.appendleft(d)
            else:
                s.append(d)
        else:
            if c == "1":
                s.append(d)
            else:
                s.appendleft(d)

if not f:
    s.reverse()

ans = "".join(s)
print(ans)
