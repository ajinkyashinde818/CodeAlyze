from collections import deque
s=deque(input())
q=int(input())
cnt=0
for i in range(q):
    query=list(input().split())
    if query[0]=="1":
        cnt+=1
    else:
        if (cnt+int(query[1]))%2==1:
            s.appendleft(query[2])
        else:
            s.append(query[2])
if cnt%2==1:
    s=reversed(s)
print("".join(s))
