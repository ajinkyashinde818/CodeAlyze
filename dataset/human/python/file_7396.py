from collections import deque

S = deque(list(input()))
Q = int(input())
q = [list(input().split()) for _ in range(Q)]
r = 0


for i in range(Q):
    if q[i][0] == "1":
        r += 1
    else:
        if (q[i][1] == "1" and r%2==0)or (q[i][1] == "2" and r%2==1 ):
            S.appendleft(q[i][2])
        else:
            S.append(q[i][2])

S = "".join(S)
if r%2==1:
    S = S[::-1]
print(S)
