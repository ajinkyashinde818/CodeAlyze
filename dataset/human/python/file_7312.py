from collections import deque

s = deque(list(input()))
q = int(input())

rev = True

for i in range(q):
    q = list(input().split())
    if(int(q[0]) == 1):
        rev = rev ^ True
    else:
        n = int(q[1])
        if((n == 1 and rev) or (n == 2 and not rev)):
            s.appendleft(q[2])
        else:
            s.append(q[2])


txt = ''
if rev:
    txt = ''.join(s)
else:
    while not(not s):
        txt += s.pop()

print(txt)
