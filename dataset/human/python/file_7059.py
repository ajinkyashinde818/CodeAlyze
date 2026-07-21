from collections import deque
s=input()
n = int(input())

f=False
q= deque(s)

for _ in range(n):
    i = input()

    if i[0] == '1': f=False if f else True
    else:
        _,a,b =i.split()
        
        if f :
            if a == '1':q.append(b)
            else:q.appendleft(b)
        else:
            if a == '1':q.appendleft(b)
            else:q.append(b)

if f: q.reverse()

for i in q:print(i,end='')
