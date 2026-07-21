from collections import deque

s=input()
q=int(input())
d=deque(s)

cnt=0
for _ in range(q):
    query=list(input().split())
    if query[0]=='1':
        cnt=(cnt+1)%2
    else:
        if query[1]=='1':
            if cnt==1:
                d.append(query[2])
            else:
                d.appendleft(query[2])
        else:
            if cnt==1:
                d.appendleft(query[2])
            else:
                d.append(query[2])
                
ans=list(d)
                
if cnt==1:
    print(*ans[::-1],sep='')
else:
    print(*ans,sep='')
