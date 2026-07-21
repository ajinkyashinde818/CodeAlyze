from collections import deque

s = deque(input())
q = int(input())

flg = 1
for _ in range(q):
    t = input()
    if t == "1":
        flg = not flg
    elif t[0] == "2":
        f = t[2]
        if f == "1":
            c = t[4]
            if flg:
                s.appendleft(c)
            else:
                s.append(c)
        elif f == "2":
            c = t[4]
            if flg:
                s.append(c)
            else:
                s.appendleft(c)

if flg:
    print(''.join(s))
else:
    print(''.join(reversed(s)))
