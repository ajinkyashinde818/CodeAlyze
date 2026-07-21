from collections import deque

S = input()
Q = int(input())
L = 1
S = deque(S)

for i in range(Q):
    A = list(input().split())
    if int(A[0]) == 1:
        L = -L
    if int(A[0]) == 2:
        A[1] = 2*int(A[1]) - 3
        if L*A[1] == -1:
            S.appendleft(A[2])
        else:
            S.append(A[2])

if L == 1:
    print(''.join(S))
else:
    print(''.join(list(reversed(S))))
