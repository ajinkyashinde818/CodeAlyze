import sys
from collections import deque
s = deque(list(input()))


q = int(input())
rev = 0
for _ in range(q):
    query = list(input().split())
    if len(query) == 1:
        rev += 1
    else:
        if query[1] == "1":
            if rev % 2 == 0:
                s.appendleft(query[2])
            else:
                s.append(query[2])

        else:
            if rev % 2 == 1:
                s.appendleft(query[2])
            else:
                s.append(query[2])

s = "".join(s)
if rev%2 == 1:
    s = s[::-1]

print(s)
