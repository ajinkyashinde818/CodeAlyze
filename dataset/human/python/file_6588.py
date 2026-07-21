from collections import deque
S=deque(list(input()))
sign=1

for i in range(int(input())):
  ls=input().split()
  if ls[0]=='1':
    sign*=-1
  else:
    if sign*int(ls[1])==1 or sign*int(ls[1])==-2:
      S.appendleft(ls[2])
    else:
      S.append(ls[2])
if sign==-1:
  S.reverse()
print(*S,sep='')
