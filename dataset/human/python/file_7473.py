from collections import deque
s= input()
q= int(input())
inv = False
head = deque()
tail = deque()
for i in range(q):
    p = input()
    if p[0]=='1':
        if inv:inv=False
        else:inv=True
    elif p[0]=='2':
        _,f,c= p.split()
        if f=='1':
            if inv:tail.append(c)
            else:head.appendleft(c)
        elif f=='2':
            if inv:head.appendleft(c)
            else:tail.append(c)
news = ''.join(head) + s + ''.join(tail)
if inv:print(news[::-1])
else:print(news)
