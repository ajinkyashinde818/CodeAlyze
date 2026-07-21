from collections import deque

s=deque(input())
q=int(input())

rev=0
for i in range(q):
  l=input().split()
  if len(l)==1:
    rev+=1
  else:
    t,f,c=l[0],l[1],l[2]

    if rev%2==0:
      if f=='1':
        s.appendleft(c)
      else:
        s.append(c)
    else:
      if f=='1':
        s.append(c)
      else:
        s.appendleft(c)

if rev%2==1:
  s.reverse()
print(''.join(s))
