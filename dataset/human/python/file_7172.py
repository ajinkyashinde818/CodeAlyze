from collections import deque
S = input()
S = deque(S)

Q = int(input())
flipped = False
for _ in range(Q):
    q = input().split()
    if q[0] == '1':
        flipped = not flipped
    elif (q[1] == '1') == flipped:
        S.append(q[2])
    else:
        S.appendleft(q[2])

print(''.join(reversed(S)) if flipped else ''.join(S))
