from collections import deque
S = input()
Q = int(input())
d = deque()
d.append(S)
reverse = False
for _ in range(Q):
    tmp = input().split()
    q = int(tmp[0])
    if q == 1:
        reverse = not reverse
    elif q == 2:
        f = int(tmp[1])
        if f == 1:
            if reverse:
                d.append(tmp[2])
            else:
                d.appendleft(tmp[2])
        elif f == 2:
            if reverse:
                d.appendleft(tmp[2])
            else:
                d.append(tmp[2])
S = "".join(d)
if reverse:
    print(S[::-1])
else:
    print(S)
