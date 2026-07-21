from collections import deque

S = input()
Q = int(input())
Query = [input().split() for _ in range(Q)]

S = deque(S)
rev = False

for TFC in Query:
    if TFC[0] == '1':
        rev = not rev
    else:
        if TFC[1] == '1':
            if rev:
                S.append(TFC[2])
            else:
                S.appendleft(TFC[2])
        else:
            if rev:
                S.appendleft(TFC[2])
            else:
                S.append(TFC[2])
if rev:
    S.reverse()
print(''.join(S))
