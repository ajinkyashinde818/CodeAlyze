from collections import deque
S=deque(input())
Q=int(input())
r='1'
for _ in range(Q):
    target = input()
    if target == '1':
        if r=='1':
            r='2'
        else:
            r='1'
    else:
        a,b,c=target.split()
        if b=='1' and r=='1':
            S.appendleft(c)
        elif b=='2' and r=='1':
            S.append(c)
        elif b=='1' and r=='2':
            S.append(c)
        else:
            S.appendleft(c)
if r=='2':
    S.reverse()
print(''.join(list(S)))
