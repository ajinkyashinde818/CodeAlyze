from collections import deque
s=deque(input())
q=int(input())
flag=0
for i in range(q):
  query=input()
  if len(query)==1:
    flag+=1
  else:
    if query[2]=="1" and flag%2==0 or query[2]=="2" and flag%2==1:
      s.appendleft(query[4])
    else:
      s.append(query[4])
if flag%2==1:
  s.reverse()
print("".join(s))
