from collections import deque
s=deque(list(input()))
q=int(input())
direction=0 #0:順 1:逆

for i in range(q):
    query=input()
    if query[0]=='1':
        direction=direction^1
    elif query[0]=='2':
        i,f,c=query.split()
        if f=='1' and direction==0:
            s.appendleft(c)
        elif f=='1' and direction==1:
            s.append(c)
        elif f=='2' and direction==0:
            s.append(c)
        elif f=='2' and direction==1:
            s.appendleft(c)


if direction==0:
    print(''.join(s))
else:
    s=''.join(s)
    s=s[::-1]
    print(s)
