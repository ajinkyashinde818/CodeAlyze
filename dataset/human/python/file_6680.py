from collections import deque
S = deque(input())
N = int(input())
is_inversed = False
for i in range(N):
    Q = input()
    if Q[0] == '1':
        is_inversed = not (is_inversed)
    else:
        if (Q[2] == '1' and is_inversed) or (Q[2] == '2' and not (is_inversed)):
            S.append(Q[4])
        else:
            S.appendleft(Q[4])
if is_inversed:
    print(''.join(list(S)[::-1]))
else:
    print(''.join(S))
