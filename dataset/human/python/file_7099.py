from collections import deque
S = list(input())
N = int(input())
rev = False
se = False
S = deque(S)
for x in range(N):
    Q = list(input().split())
    if Q[0] == "1":
        if rev:
            rev = False
        elif se:
            rev = True
    else:
        se =True
        if Q[1] == "1":
            if rev:
                S.append(Q[2])
            else:
                S.appendleft(Q[2])
        else:
            if rev:
                S.appendleft(Q[2])
            else:
                S.append(Q[2])

S = list(S)
if rev:
    S = reversed(S)
    
ans = "".join(S)
print(ans)
