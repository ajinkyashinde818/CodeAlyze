from collections import deque
S = list(input())
S = deque(S)
rev = False
Q = int(input())
for _ in range(Q):
    T = list(map(str,input().split()))
    if T[0] == '1':
        if rev:
            rev = False
        else:
            rev = True
    if T[0] == '2':
        if T[1] == '1':
            if rev:
                S.append(T[2])
            else:
                S.appendleft(T[2])
        if T[1] == '2':
            if rev:
                S.appendleft(T[2])
            else:
                S.append(T[2])
if rev:
    S = list(reversed(S))
    print("".join(S))
else:
    S = list(S)
    print("".join(S))
