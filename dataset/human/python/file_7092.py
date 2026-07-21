from collections import deque

s = deque(input())
q = int(input())
count = 0
for i in range(q):
    query = list(input().split())
    if query[0] == "1":
        count += 1
    else:
        if count % 2 == 0:
            if query[1] == "1":
                s.appendleft(query[2])
            else:
                s.append(query[2])
        else:
            if query[1] == "2":
                s.appendleft(query[2])
            else:
                s.append(query[2])

if count % 2 == 1:
    s.reverse()

for i in s:
    print(i, end="")
