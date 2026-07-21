from collections import deque
S=deque(input())
q=int(input())
rev=False
for i in range(q):
  c=list(input().split())
  if c[0]=='1':
    rev=not rev
  elif c[1]=='1' and rev==False:
    S.appendleft(c[2])
  elif c[1]=='2' and rev==True:
    S.appendleft(c[2])
  else:
    S.append(c[2])
if rev:
  S.reverse()
ans=''.join(S)
print(ans)
