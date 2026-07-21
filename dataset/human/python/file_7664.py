from collections import deque

S = deque(map(str, input().split()))
Q = int(input())
Left = True

for i in range(Q):
    TFC = input()

    if TFC[0] == "1":
        Left = not Left

    else:
        _, f, c = TFC[0], TFC[2], TFC[4]
        f = int(f)
        if Left and (f == 1):
            S.appendleft(c)
        elif Left and (f == 2):
            S.append(c)
        elif (not Left) and (f == 1):
            S.append(c)
        else:
            S.appendleft(c)

T = "".join(S)
if not Left:
    T = T[::-1]

print(T)
