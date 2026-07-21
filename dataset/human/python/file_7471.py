from collections import deque
s=input()
q=int(input())
t=[input() for i in range(q)]
l=deque(list(s))
m=0
for i in range(q):
  if int(t[i][0])==1:
    m+=1
  else:
    if m%2==0:
      if int(t[i][2])==1:
        l.appendleft(t[i][4]) 
      else:
        l.append(t[i][4])
    else:
      if int(t[i][2])==2:
        l.appendleft(t[i][4]) 
      else:
        l.append(t[i][4])
if m%2==1:
  l.reverse()
print(''.join(l))
