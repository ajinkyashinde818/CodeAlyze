from collections import deque

d = deque()
inversion = 1

s = input()

for i in range(len(s)):
    d.append(s[i])

q = int(input())

for i in range(q):
    qn = list(input().split())
    if qn[0] == "1":
        inversion *= -1
    elif qn[0] == "2":
        if qn[1] == "1":
            if inversion == 1:
                d.appendleft(qn[2])
            elif inversion == -1:
                d.append(qn[2])
        if qn[1] == "2":
            if inversion == 1:
                d.append(qn[2])
            elif inversion == -1:
                d.appendleft(qn[2])

for i in range(len(d)):
    if inversion == 1:
        print(d.popleft(), end="")
    if inversion == -1:
        print(d.pop(), end="")

print()
