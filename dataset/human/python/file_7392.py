from collections import deque
que=deque(input())
q=int(input())
rev=False
for i in range(q):
    t=input()
    if t=='1':
        rev=not rev
    else:
        tt,f,c=t.split()
        if (rev==False and f=='1')or(rev and f=='2'):
            que.appendleft(c)
        else:
            que.append(c)
if rev:
    que.reverse()
print(''.join(que))
