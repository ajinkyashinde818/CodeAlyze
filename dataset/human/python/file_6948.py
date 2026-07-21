from collections import deque

s = deque(list(input()))
q = int(input())

cont = 0
for i in range(q):
    q_uery = list(map(str, input().split()))
    if int(q_uery[0]) == 1:
        cont += 1
    if int(q_uery[0]) == 2:
        if (int(q_uery[1]) + cont) % 2 == 0:
            s.append(q_uery[2])
        else:
            s.appendleft(q_uery[2])
if cont % 2 == 1:
    s.reverse()

print(''.join(s))
