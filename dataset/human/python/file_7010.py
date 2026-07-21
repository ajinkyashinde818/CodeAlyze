from collections import deque
import sys
input = sys.stdin.readline

S = deque(input().rstrip())
Q = int(input())
rev = False
for _ in range(Q):
    q = input().split()
    if q[0] == '1':
        rev = rev ^ True
    else:
        F, C = q[1:]
        if (F == '1') ^ rev:
            S.appendleft(C)
        else:
            S.append(C)
S = list(S)
if rev:
    S.reverse()
print(''.join(S))
