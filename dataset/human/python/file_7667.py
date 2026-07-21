from collections import deque

s = deque(input())
q = int(input())

flag = 1

for _ in range(q):
    tfc = input().split()
    if tfc[0] == "1":
        flag *= -1

    elif tfc[0] == "2":
        if (tfc[1] == "1" and flag == 1) or (tfc[1] == "2" and flag == -1):
            s.appendleft(tfc[2])
        elif (tfc[1] == "1" and flag == -1) or (tfc[1] == "2" and flag == 1):
            s.append(tfc[2])
else:

    if flag == -1:
        s = list(s)[::-1]

print("".join(s))
