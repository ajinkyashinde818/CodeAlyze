from collections import deque
s = deque(input())
qn = int(input())
q = []
rev = False

for i in range(qn):
    qi = input().split()
    if qi[0] == "1":
        rev = not rev
    else:
        if rev:
            if qi[1] == "1":
                qi[1] = "2"
            else:
                qi[1] = "1"
        q.append((2, int(qi[1]), qi[2]))
for i in range(len(q)):
    if q[i][0] == 2:
        if q[i][1] == 1:
            s.appendleft(q[i][2])
        else:
            s.append(q[i][2])
if rev:
    s = list(s)[::-1]
print("".join(s))
