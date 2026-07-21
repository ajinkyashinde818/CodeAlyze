from collections import deque
S = deque(list(input()))
Q = int(input())
parity = 0

for i in range(Q):
    query = input().split()
    if len(query) == 1:
        parity += 1
    else:
        if int(query[1]) == 1 + (parity % 2):
            S.appendleft(query[2])
        else:
            S.append(query[2])
S = ''.join([c for c in S])
if parity % 2 == 1:
    S = S[::-1]
print(S)
