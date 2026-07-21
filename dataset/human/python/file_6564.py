from collections import deque
S = deque(list(input()))
Q = int(input())

flag = False
for _ in range(Q):
    IN = list(map(str,input().split()))

    if IN[0] == "1":
        flag = not flag
        continue

    _,F,C = IN
    if flag:
        if F == "1":
            S.append(C)
        else:
            S.appendleft(C)
    else:
        if F == "1":
            S.appendleft(C)
        else:
            S.append(C)

if flag:
    print(*reversed(S),sep="")
else:
    print(*S,sep="")
