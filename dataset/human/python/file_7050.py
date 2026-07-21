from collections import deque
s = list(input())
q = int(input())

s = deque(s)
rev = 0

for i in range(q):
    t = list(input().split())
    if len(t) == 1:
        rev += 1
        continue
    if t[1] == '1':
        if rev % 2 == 0:
            s.appendleft(t[2])
        else:
            s.append(t[2])
    else:
        if rev % 2 == 0:
            s.append(t[2])
        else:
            s.appendleft(t[2])
if rev % 2 != 0:
    s.reverse()

print(''.join(s))
