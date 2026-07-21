from collections import deque
s = deque(input())
q = int(input())
rev = False
for _ in range(q):
    inp = [x for x in input().split()]
    if inp[0] == "1":
        rev = not rev
    else:
        if inp[1] == "1":
            if rev:
                s.append(inp[2])
            else:
                s.appendleft(inp[2])
        else:
            if rev:
                s.appendleft(inp[2])
            else:
                s.append(inp[2])

if rev:
    s.reverse()
    print("".join(s))
else:
    print("".join(s))
