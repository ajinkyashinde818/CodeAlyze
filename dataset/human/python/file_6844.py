from queue import deque
s = deque([i for i in input()])
Q = int(input())
 
f = 0
 
for _ in range(Q):
    q = input()
    if int(q[0]) == 1:
        f = abs(f-1)
        continue
    
    _, F, c = q.split()
    if f+int(F) % 2 == 1:
        s.appendleft(c)
    else:
        s.append(c)
        
if f:
    print(''.join(reversed(s)))
else:
    print(''.join(s))
