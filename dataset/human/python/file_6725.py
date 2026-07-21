from collections import deque
s=list(input())
d=deque(s)
q=int(input())
ct=0
for i in range(q):
  l=list(input().split())
  if l[0]=='1':
    ct+=1
  else:
    if ct%2==0:
      if l[1]=='1':
        d.appendleft(l[2])
      else:
        d.append(l[2])
    else:
      if l[1]=='2':
        d.appendleft(l[2])
      else:
        d.append(l[2])
d=list(d)
if ct%2==1:
  d.reverse()
print(''.join(d))
