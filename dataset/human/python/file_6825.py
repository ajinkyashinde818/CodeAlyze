from collections import deque

s = deque(input())
q = int(input())
re = False

for i in range(q):
    try:
        a,f,c = map(str, input().split())
    except ValueError:
        re = not re
        continue

    if f == "1":
        if not re:
            s.appendleft(c)
        else:
            s.append(c)
    else:
        if not re:
            s.append(c)
        else:
            s.appendleft(c)

if re:
    s = list(reversed(s))

print("".join(s))
