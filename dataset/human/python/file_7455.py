from collections import deque
s,q=deque([*input()]),int(input())
judge=False
for i in range(q):
  t=input().split()
  if len(t)==1:
    judge = not judge
  else:
    t,f,c=t
    if not judge and f=='1': s.appendleft(c)
    elif not judge and f=='2': s.append(c)
    elif judge and f=='1': s.append(c)
    else: s.appendleft(c)
if judge: s.reverse()
print(*s,sep='')
