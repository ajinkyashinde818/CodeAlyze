from collections import deque

S = input()
Q = int(input())

ANS = deque(S)

rev = 0

for _ in range(Q):
    query = input().split(' ')
    if len(query) == 1:
        rev = rev ^ 1
    else:
        f, c = int(query[1]), query[2]
        if (f - 1) ^ rev:
            ANS.append(c)
        else:
            ANS.appendleft(c)

if rev:
    ANS.reverse()

print(''.join(ANS))
