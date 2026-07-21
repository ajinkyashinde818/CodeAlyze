import sys
from collections import deque
input = sys.stdin.readline

S = input()

dq = deque(S.rstrip())
Q = int(input());

reverse = False

for _ in range(Q):
    q = input().split()
    if q[0] == '1':
        reverse ^= 1
    else:
        F, C = q[1:]
        if reverse:
            if F == '1':
                dq.append(C)
            else:
                dq.appendleft(C)
        else:
            if F == '1':
                dq.appendleft(C)
            else:
                dq.append(C)

ans = ""
if reverse:
    while dq:
        ans += dq.pop()
else:
    while dq:
        ans += dq.popleft()
print(ans)
