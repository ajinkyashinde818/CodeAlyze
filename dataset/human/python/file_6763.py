from collections import deque
S = deque(list(input()))
q = int(input())
r = False
for _ in range(q):
    t = input().split()
    if len(t) == 1:
        r = not r
    else:
        t[1] = int(t[1]) - 1
        if (not t[1] and not r) or (t[1] and r):
            S.appendleft(t[2])
        else:
            S.append(t[2])
if r:
    S = list(S)
    print(''.join(S[::-1]))
else:
    print(''.join(S))
