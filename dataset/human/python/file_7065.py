from collections import deque

S = list(input())
Q = int(input())

d = deque(S)
head = "l"

for _ in range(Q):
    q = input()
    if len(q) == 1:
        if head == "l":
            head = "r"
        else:
            head = "l"
    else:
        T, F, C = q.split()
        if int(F) == 1:
            if head == "l":
                d.appendleft(C)
            else:
                d.append(C)
        else:
            if head == "l":
                d.append(C)
            else:
                d.appendleft(C)
if head == "l":
    print("".join(list(d)))
else:
    print("".join(list(d)[::-1]))
