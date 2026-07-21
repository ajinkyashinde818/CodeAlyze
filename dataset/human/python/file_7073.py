from collections import deque
s=list(str(input()))
s=deque(s)
q=int(input())
cnt=0
for i in range(q):
    que=list(input().split())
    if len(que)==1:
        cnt+=1
    if len(que)!=1 and cnt%2==0:
        if int(que[1])==1:
            s.appendleft(que[2])
        elif int(que[1])==2:
            s.append(que[2])
    if len(que)!=1 and cnt%2!=0:
        if int(que[1])==1:
            s.append(que[2])
        elif int(que[1])==2:
            s.appendleft(que[2])
if cnt%2!=0:
    s.reverse()
print(''.join(s))
