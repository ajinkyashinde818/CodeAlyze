import sys
from collections import deque

sys.setrecursionlimit(1000000)
input = lambda: sys.stdin.readline().rstrip()

S = deque(input())
Q = int(input())
rev = False
for _ in range(Q):
    query = input().split()
    if len(query) == 1:
        rev = not rev
    else:
        if (not rev and query[1] == '1') or (rev and query[1] == '2'):
            S.appendleft(query[2])
        else:
            S.append(query[2])

if rev:
    print(''.join(reversed(S)))
else:
    print(''.join(S))
