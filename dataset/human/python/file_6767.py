from collections import deque
s = deque(input())
Q = int(input())

reverse = False
for i in range(Q):
    q = input()
    if q == "1":
        reverse = False if reverse else True
    else:
        t, f, c = q.split(" ")
        if f == "1":
            if reverse:
                s.append(c)
            else:
                s.appendleft(c)
        else:
            if reverse:
                s.appendleft(c)
            else:
                s.append(c)
ans = ''.join(s)
if reverse:
    print(ans[::-1])
else:
    print(ans)
