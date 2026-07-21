from collections import deque

s = deque(str(input()))
q = int(input())
hanten = 0

for i in range(q):
    x = input().split()
    if len(x) == 1:
        t = x[0]
        if t == "1" and hanten == 0:
            hanten = 1
        elif t == "1" and hanten == 1:
            hanten = 0

    else:
        f = int(x[1])
        c = str(x[2])
        if f == 1 and hanten == 0:
            s.appendleft(c)

        elif f == 1 and hanten == 1:
            s.append(c)

        elif f == 2 and hanten == 0:
            s.append(c)

        elif f == 2 and hanten == 1:
            s.appendleft(c)

else:
    if hanten == 1:
        s.reverse()

print("".join(s))
