from collections import deque
s = input()
q=int(input())
d=deque(s)
r=True

for _ in range(q):
    buf = input()
    if buf[0]=='1':
        if r:
            r=False
        else :
            r=True
    elif buf[0]=='2':
        c=buf.split()
        if (c[1]=='1' and r) or (c[1]=='2' and r==False):
            d.appendleft(c[2])
        else:
            d.append(c[2])
if r==False:
    d.reverse()
for i in d:
    print(i,end='')
