from collections import deque
d = deque()
s = input()

for i in s:
    d.append(i)

q = int(input())

reverse = 0
for i in range(q):
    query = input().split()
    if query[0] == "1":
        t = int(query[0])
    else:
        t = int(query[0])
        f = int(query[1])
        c = query[2]

    if t == 1:
        reverse = 1 - reverse
    else:
        if reverse == 1:
            f = f - 1

        if f == 1:
            d.appendleft(c)
        else:
            d.append(c)
if reverse == 1:
    d.reverse()
print("".join(d))
