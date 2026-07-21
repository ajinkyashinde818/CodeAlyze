from collections import deque
s = deque(input())
q = int(input())

state = 0
for i in range(q):
    query = list(input().split())
    if query[0] == "1":
        state += 1
    else:
        if (int(query[1]) + state) % 2 == 1:
            s.appendleft(query[2])
        else:
            s.append(query[2])

if state % 2 == 1:
    s = list(s)[::-1]

print("".join(s))
