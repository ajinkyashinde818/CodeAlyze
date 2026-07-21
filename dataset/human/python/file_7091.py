from collections import deque

d=deque()
s=input()
for i in s:
  d.append(i)
q=int(input())
flag=1
t = [input().split() for l in range(q)]
for i in range(q):
  if t[i][0]=='1':
    flag=flag*(-1)
  else:
    if t[i][1]=='1' and flag==1:
      d.appendleft(t[i][2])
    elif t[i][1]=='1' and flag==-1:
      d.append(t[i][2])
    elif t[i][1]=='2' and flag==1:
      d.append(t[i][2])
    elif t[i][1]=='2' and flag==-1:
      d.appendleft(t[i][2])
if flag==-1:
  d.reverse()
d="".join(list(d))
print(d)
