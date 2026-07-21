import sys
from collections import deque

readline = sys.stdin.readline

S = list(readline().rstrip())
Q = int(readline())
a = deque([])
b = deque([])
s = 1

for _ in range(Q):
    query = readline().rstrip()
    if query == '1':
        s = -s
    else:
        _, F, C = map(str, query.split())
        if s == 1:
            if F == '1':
                a.appendleft(C)
            else:
                b.append(C)
        else:
            if F == '1':
                b.append(C)
            else:
                a.appendleft(C)

answer = list(a) + S + list(b)
answer = ''.join(answer)
if s == -1:
    answer = answer[::-1]
print(answer)
