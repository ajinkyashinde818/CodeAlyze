s=input()
q=int(input())
cnt=0
from collections import deque
s=deque(s)
for i in range(q):
    j=tuple(input().split())
    if  len(j)==3 :
        if (cnt+int(j[1]))%2:
            s.appendleft(j[2])
        else:
            s.append(j[2])
    else:
        cnt+=1
if cnt%2==0:
    print("".join(s))
else:
    print("".join(reversed(list(s))))
