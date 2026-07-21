from collections import deque

S = input()
Q = int(input())

s = deque(S)

rev = False
for _ in range(Q):
    q = input().split()
    t = int(q[0])
    if t == 1:
        rev = not rev
    else:
        f, c = int(q[1]), q[2]
        if (f == 1 and not rev) or (f == 2 and rev):
            s.appendleft(c)
        else:
            s.append(c)

s = ''.join(s)
if rev:
    s = s[::-1]
print(s)
