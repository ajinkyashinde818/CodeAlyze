from collections import deque
s = deque(input())
q = int(input())
query = [list(map(str, input().split())) for _ in range(q)]

order = True
for i in query:
    if i[0] == "1":
        order = not order
    elif i[1] == "1":
        if order:
            s.appendleft(i[2])
        else:
            s.append(i[2])
    else:
        if order:
            s.append(i[2])
        else:
            s.appendleft(i[2])

if not order:
    s.reverse()
print("".join(s))
