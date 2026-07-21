from collections import deque

S = input()
Q = int(input())
Queries = [input().split() for i in range(Q)]
dq = deque(S)

f = 0

for a in Queries:
    if a[0] == '1':
        f ^= 1
    else:
        if f == (int(a[1])-1):
            dq.appendleft(a[2])
        else:
            dq.append(a[2])

if f:
    dq.reverse()

print(''.join(dq))
