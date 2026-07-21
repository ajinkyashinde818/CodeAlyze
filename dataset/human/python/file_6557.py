from collections import deque
S = input()
SS = deque()
for s in S:
    SS.append(s)
Q = int(input())
Que = [list(input().split()) for _ in range(Q)]
r = 0

for q in Que:
    if q[0] == '1':
        r += 1
    else:
        if (q[1] == '1' and r % 2 == 1) or (q[1] == '2' and r % 2 == 0):
            SS.append(q[2])
        else:
            SS.appendleft(q[2])
if r % 2 == 0:
   while len(SS) > 0:
        s = SS.popleft()
        print(s, end='')    
else:
    while len(SS) > 0:
        s = SS.pop()
        print(s, end='')
print('')
