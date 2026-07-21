from collections import deque

s=deque(list(input()))
flag=0
for i in range(int(input())):
  dir=input().split()
  if int(dir[0])==1:flag+=1
  else:
    if int(dir[1])==1:
      if flag%2==0:s.appendleft(dir[2])
      else:s.append(dir[2])
    else:
      if flag%2==0:s.append(dir[2])
      else:s.appendleft(dir[2])
s=list(s)
if flag%2==1:s.reverse()
print(*s,sep='')
