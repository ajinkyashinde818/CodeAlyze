from collections import deque
d=deque()
d.append(input())
q=int(input())
r=1
for i in range(q):
  q2=input().split()
  if int(q2[0])==1:
    r*=-1
  else:
    if (r==1 and int(q2[1])==1) or (r==-1 and int(q2[1])==2):
        d.appendleft(q2[2])
    else:
        d.append(q2[2])

print("".join(d) if r==1 else "".join(d)[::-1])
