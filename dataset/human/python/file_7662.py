from collections import deque

S = deque(list(input()))

f = False

for i in range(int(input())):
    q = input().split()
    
    if q[0] == '1': f = not f
    else:
        if not f:
            if q[1] == '1': S.appendleft(q[2])
            else: S.append(q[2])
        else:
            if q[1] == '1': S.append(q[2])
            else: S.appendleft(q[2])
        
if f: S.reverse()
print(''.join(map(str, list(S))))
