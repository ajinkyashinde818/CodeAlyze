import sys
input = sys.stdin.readline
s=input().strip()
q=int(input())
from collections import deque
que=deque(s)
mae=1
for _ in range(q):
    query=list(input().split())
    if query[0]=="1":
        mae*= -1
    else:
        if mae==1:
            if query[1]=="1":
                que.appendleft(query[2])
            else:
                que.append(query[2])
        else:
            if query[1]=="1":
                que.append(query[2])
            else:
                que.appendleft(query[2])
    #print(que)
if mae==1:
    print("".join(que))
else:
    print("".join(list(que)[::-1]))
