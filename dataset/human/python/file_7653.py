from collections import deque

s = input()
d = deque()
for i in s:
    d.append(i)
q = int(input())

state = 0


for i in range(q):
    In = input()
    if In == '1':
        state = (state + 1)%2
    else:
        t,f,c = In.split()
        k = (f=='2')
        if (k+state)%2==0:
            d.appendleft(c)
        else:
            d.append(c)
if state==0:
    print(*list(d),sep='')
else:
    t = list(d)[::-1]
    print(*t, sep='')
