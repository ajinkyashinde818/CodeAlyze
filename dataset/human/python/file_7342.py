from collections import deque
que=deque(input())
rev=False
for _ in range(int(input())):
    t=input()
    if t=='1':
        rev=not rev
    else:
        tt,f,c=t.split()
        if (f=='1' and rev==False)  or (f=='2' and rev):
            que.appendleft(c)
        else:
            que.append(c)
if rev:
    que.reverse()

print(''.join(que))
