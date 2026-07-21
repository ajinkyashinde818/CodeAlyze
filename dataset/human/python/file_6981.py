from collections import deque

S = input()
Q = int(input())
L = [list(input().split()) for i in range(Q)]

hanten = 0
t = deque([S])

for l in L:
    if len(l) == 1:
        hanten += 1
    elif (l[1] == '1' and hanten % 2 == 0) or (l[1] == '2' and hanten % 2 == 1):
        t.appendleft(l[2])
    else:
        t.append(l[2])

ans = ''.join(t)
if hanten % 2 == 1:
    ans = ''.join(list(reversed(ans)))
print(ans)
