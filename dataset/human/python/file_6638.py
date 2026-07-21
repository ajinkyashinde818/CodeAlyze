from collections import deque


S = deque(input())
Q = int(input())
flag = 1

for _ in range(Q):
    q = input().split()
    if q[0] == "1":
        flag *= -1
    elif q[1] == "1":
        if flag == 1:
            S.appendleft(q[2])
        else:
            S.append(q[2])
    else:
        if flag == 1:
            S.append(q[2])
        else:
            S.appendleft(q[2])
s = list(S)
if flag == 1:
    print("".join(s))
else:
    for i in reversed(s):
        print(i, end="")
