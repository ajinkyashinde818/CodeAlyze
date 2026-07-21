from collections import deque

S = deque(input())
Q = int(input())
flg = True
for _ in range(Q):
    query = input()
    if query[0] == "1":
        flg = not flg
    else:
        _,F,C = query.split()
        if (F == "1" and flg) or (F == "2" and not flg):
            S.appendleft(C)
        else:
            S.append(C)
if not flg:
    S.reverse()

print(''.join(S))
