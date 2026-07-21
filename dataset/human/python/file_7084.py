from collections import deque

s = deque(input())
q = int(input())

direction = 0
for _ in range(q):
    a = input()
    if a[0]=='1':
        direction+=1
    else:
        t,f,c = a.split()
        if f=='1':
            if direction%2==0:
                s.appendleft(c)
            else:
                s.append(c)
        else:
            if direction%2==0:
                s.append(c)
            else:
                s.appendleft(c)

if direction%2==1:
    s.reverse()
print(''.join(s))
