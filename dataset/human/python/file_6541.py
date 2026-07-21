from collections import deque

S = deque(input())
Q = int(input())

sign = 1
head = ""
tail = ""
for i in range(Q):
    Q = input().split()
    if Q[0] == "1":
        sign *= -1
    else:
        if int(Q[1]) * sign == 1:
            S.appendleft(Q[2])
        elif int(Q[1]) * sign == -1:
            S.append(Q[2])
        elif int(Q[1]) * sign == 2:
            S.append(Q[2])
        elif int(Q[1]) * sign == -2:
            S.appendleft(Q[2])

if sign==1:
    print("".join(S))
elif sign==-1:
    S.reverse()
    print("".join(S))
