from collections import deque

q = deque(list(input()))
Q = int(input())

flg = 0
for _ in range(Q):
    i, *x = input().split()
    if i == "1":
        flg = 1 - flg
    else:
        f, c = x
        if flg == 0:
            if f == "1":
                q.appendleft(c)
            else:
                q.append(c)
        else:
            if f == "1":
                q.append(c)
            else:
                q.appendleft(c)

if flg == 0:
    print("".join(q))
else:
    print("".join(reversed(q)))
