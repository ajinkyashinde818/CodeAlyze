from collections import deque

s = deque(input())
q = int(input())

rev = False
for i in range(q):
    query = input().split()
    if query[0] == "1":
        rev ^= True
    else:
        if (query[1] == "1" and not rev) or (query[1] == "2" and rev):
            s.appendleft(query[2])
        else:
            s.append(query[2])

if rev:
    print("".join(list(s)[::-1]))
else:
    print("".join(list(s)))
