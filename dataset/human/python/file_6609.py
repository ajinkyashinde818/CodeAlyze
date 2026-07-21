s = input()
q = int(input())

from collections import deque
s = deque(s)
count = 0
for i in range(q):
    query = input()
    if query == "1":
        count += 1
    else:
        t,f,c = query.split()
        if f == "1":
            if count % 2 == 0:
                s.appendleft(c)
            else:
                s.append(c)
        else:
            if count % 2 == 0:
                s.append(c)
            else:
                s.appendleft(c)
s = "".join(s)
if count % 2 == 0:
    print(s)
else:
    print(s[::-1])
