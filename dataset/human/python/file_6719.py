from collections import deque
import sys
input=sys.stdin.readline
S=input().splitlines()[0]
Q = int(input())
qs = [input().split() for _ in range(Q)]
flipcnt = 0
S =deque(S)
for q in qs:
    if len(q) == 1:
        flipcnt += 1
        continue
    else:
        if (int(q[1]) + flipcnt) % 2 == 1:
            #前
            S.appendleft(q[2])
        else:
            S.append(q[2])
    #print(S)

if flipcnt % 2 == 1:
    S.reverse()

print(''.join(S))
