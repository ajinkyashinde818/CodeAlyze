from collections import deque

s = input()
N = int(input())

S = []
for i in range(len(s)):
    S.append(s[i])

d = deque(S)
    
back_count = 0
for i in range(N):
    Q = list(map(str, input().split()))
    Q[0] = int(Q[0])
    if Q[0] == 1:
        if back_count == 0:
            back_count = 1
        else:
            back_count = 0
    else:
        Q[1] = int(Q[1])
        if back_count == 0:
            if Q[1] == 1:
                d.appendleft(Q[2])
            else:
                d.append(Q[2])
        else:
            if Q[1] == 1:
                d.append(Q[2])
            else:
                d.appendleft(Q[2])

S = list(d)
if back_count == 0:
    print("".join(S))
else:
    S = S[::-1]
    print("".join(S))
