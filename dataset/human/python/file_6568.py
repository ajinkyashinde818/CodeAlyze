from collections import deque
s=deque(input())
n=int(input())
r=0
for i in range(n):
    strlist=input()
    if strlist[0]=='1':
        r+=1
    elif strlist[0]=='2' and strlist[2] == '1':
        if r%2==0:
            s.appendleft(strlist[4])
        else:
            s.append(strlist[4])
    elif strlist[0]=='2' and strlist[2] =='2':
        if r%2==0:
            s.append(strlist[4])
        else:
            s.appendleft(strlist[4])
if r%2==0:
    for s_ in s:
        print(s_, end='')
else:
    s.reverse()
    for s_ in s:
        print(s_, end='')
