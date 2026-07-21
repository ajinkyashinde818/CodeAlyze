from collections import deque
S=input()
Q=int(input())
q=deque(list(S))
directed=True
for i in range(Q):
    command=input().split()
    if command[0]=="1":
        directed=not(directed)
    else:
        if (command[1]=="1")==directed:
            q.appendleft(command[2])
        else:
            q.append(command[2])
ans=""
while(len(q)>0):
    if directed:
        t=q.popleft()
        ans+=t
    else:
        t=q.pop()
        ans+=t
print(ans)
