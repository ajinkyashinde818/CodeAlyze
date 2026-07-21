from collections import deque

s = input()
d = deque()
header = 1
for i in s:
    d.append(i)
q = int(input())

for i in range(q):
    data = input().split()
    if len(data) == 1:
        header *= -1
    else:
        f = int(data[1])
        c = data[2]
        if header == 1:
            if f == 1:
                d.appendleft(c)
            else:
                d.append(c)
        else:
            if f == 1:
                d.append(c)
            else:
                d.appendleft(c)

if header == -1:
    d.reverse()

s = list(d)
s = "".join(s)

print(s)
