from collections import deque
s = deque(input())
q = int(input())
rev = 1
for i in range(q):
    t = input().split()
    if t[0]=="1":
        rev *= -1
    else :
        if t[1]=='1':
            if rev == 1:
                s.appendleft(t[2])
            else :
                s.append(t[2])
        else :
            if rev == 1:
                s.append(t[2])
            else :
                s.appendleft(t[2])
if rev == 1:
    print(''.join(s))
else :
    print(''.join(reversed(s)))
