from collections import deque

s = input()
q = int(input())

que = deque(s)

flipped = False
for i in range(q):
    query = input()
    if query[0] == "1":
        flipped = not flipped
    else:
        t, f, c = query.split()
        if (f == "1") ^ flipped:
            que.appendleft(c)
        else:
            que.append(c)
s = "".join(que)
if flipped:
    s = s[::-1]
print(s)
