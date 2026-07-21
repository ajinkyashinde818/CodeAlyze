from collections import deque
s = deque(input())
q = int(input())
l = list(list(input().split()) for _ in range(q))
t = 0
for i in l:
  if len(i)==1:
    t += 1
  else:
    a,f,c = i
    if (f=="1" and t%2==0) or (f=="2" and t%2==1) :
      s.appendleft(c)
    else:
      s.append(c)
if t%2==1:
  s.reverse()
print(*s,sep="")
