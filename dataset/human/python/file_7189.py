from collections import deque
import sys
input2 = sys.stdin.readline()

s=list(input2)
Q=int(input())
direction=0
d=deque(s)
d.pop()

for i in range(Q):
    tmp=list(input())
    if tmp[0] == "1":
        if direction == 0:
            direction = 1
        else:
            direction = 0
    else:
        if tmp[2] == "1":
            if direction == 0:
                d.appendleft(tmp[4])
            else:
                d.append(tmp[4])
        else:
            if direction == 0:
                d.append(tmp[4])
            else:
                d.appendleft(tmp[4])
if direction==1:
    d.reverse()
ans=list(d)
answer="".join(ans)
print(answer)
