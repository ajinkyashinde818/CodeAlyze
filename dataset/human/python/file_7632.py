from collections import deque

S = input()
Q = int(input())
rev = False
ans = deque(S)
for i in range(Q):
    tfc = input()
    if tfc == '1':
        rev = not rev
    else:
        t,f,c = tfc.split()
        if f == '1':
            if rev: ans.append(c)
            else: ans.appendleft(c)
        elif f == '2':
            if rev: ans.appendleft(c)
            else: ans.append(c)

if rev: ans.reverse()

print(''.join(ans))
