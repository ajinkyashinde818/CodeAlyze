from collections import deque

S = deque(input())
Q = int(input())
cnt = 2
for _ in range(Q):
    L = input().split()
    if L[0] == "1":
        cnt += 1
    elif L[0] == "2":
        if L[1] == "1" and (cnt)%2 == 0:
            S.appendleft(str(L[2]))
        elif L[1] == "1" and (cnt)%2 != 0:
            S.append(str(L[2]))
        elif L[1] == "2" and (cnt)%2 == 0:
            S.append(str(L[2]))
        elif L[1] == "2" and (cnt)%2 != 0:
            S.appendleft(str(L[2]))
S ="".join(S)
if cnt%2 != 0:
        print(S[::-1])
else:
        print(S)
