from collections import deque

s = deque(input(""))
Q = int(input())
c = 0

for i in range(Q):
    t = input("")
    if len(t) == 1:
        c += 1
    elif t[2] == "1":
        if c % 2 == 0:
            s.appendleft(t[4])
        else:
            s.append((t[4]))
    else:
        if c % 2 == 0:
            s.append(t[4])
        else:
            s.appendleft(t[4])

if c % 2 == 0:
    for i in s:
        print(i,end="")
else:
    for i in range(len(s)-1,-1,-1):
        print(s[i],end="")
