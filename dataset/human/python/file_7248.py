from collections import deque

S = input()
dq = deque(S)

Q = int(input())
inverse = False
for _ in range(Q):
    query = list(input().split())
    if query[0] == '1':
        inverse = not inverse
    else:
        tmp = (int(query[1]) - 1) ^ inverse
        if tmp: dq.append(query[2])
        else: dq.appendleft(query[2])

if inverse: dq.reverse()
for c in dq:
    print(c, end='')
print('')
