from collections import deque
s=deque(input())
q=int(input())
flag=0
for _ in range(q):
  query=input().split()
  if len(query)==1:
    flag=(flag+1)%2
  else:
    if (int(query[1])+flag)%2:
      s.appendleft(query[2])
    else:
      s.append(query[2])
print(''.join(s) if flag==0 else ''.join(reversed(s)))
