import sys
from collections import deque

S = input()
Q = int(input())
QUERY = sys.stdin.readlines()

state = 0
q = deque()
for s in S:
    q.append(s)

for i in range(Q):
    query = QUERY[i]
    if query[0] == '1':
        state ^= 1
    else:
        _, F, C = query.split()
        F = int(F) - 1
        if state ^ F:
            q.append(C)
        else:
            q.appendleft(C)

ans = []
if state == 0:
    while q:
        ans.append(q.popleft())
else:
    while q:
        ans.append(q.pop())

print(''.join(ans))
