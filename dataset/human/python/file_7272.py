from collections import deque

s = input()
q = int(input())

reverse = False
count = 0
s = deque(s)
for i in range(q):
    qu = input()
    if qu[0] == "1":
        count += 1
        if reverse:
            reverse = False
        else:
            reverse = True
    else:
        _, f, c = qu.split()
        if reverse:
            if f == "1":
                s.append(c)
            else:
                s.appendleft(c)
        else:
            if f == "1":
                s.appendleft(c)
            else:
                s.append(c)

s = "".join(s)

if count % 2:
    print(s[::-1])
else:
    print(s)
