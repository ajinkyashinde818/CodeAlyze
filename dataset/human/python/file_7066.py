from collections import deque
S = deque(input())
Q = int(input())
Qr = [list(input().split()) for i in range(Q)]
isForward = True
for i in range(Q):
    if Qr[i][0] == "1":
        isForward = not(isForward)
    elif (isForward and  Qr[i][1] == "1") or (not(isForward) and Qr[i][1] == "2"):
        S.appendleft(Qr[i][2])
    else:
        S.append(Qr[i][2])
S = list(S)
if not(isForward):
    S.reverse()
print("".join(S))
