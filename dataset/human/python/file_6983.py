from collections import deque
S=input()
Q=int(input())
query=[list(map(str,input().split())) for _ in range(Q)]

d=deque(S)
reverse=False
for q in query:
  if len(q)==1:
    reverse=not reverse
  else:
    _,f,c=q
    if f=='1':
      d.append(c) if reverse else d.appendleft(c)
    else:
      d.appendleft(c) if reverse else d.append(c)
print(*reversed(d),sep='') if reverse else print(*d,sep='')
