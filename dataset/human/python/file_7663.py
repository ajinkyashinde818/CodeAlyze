from collections import deque

s = deque(input())
q = int(input())
first = 1

for i in range(q):
    t = input().split()
    if int(t[0]) == 1:
        first *= -1
    else:
        f = int(t[1])
        c = t[2]
        
        if first == 1:
            if f == 1:
                s.appendleft(c)
            elif f == 2:
                s.append(c)
        else:
            if f == 1:
                s.append(c)
            elif f == 2:
                s.appendleft(c)

S = "".join(s)
if first == 1:
    print(S)
else:
    print(S[::-1])
