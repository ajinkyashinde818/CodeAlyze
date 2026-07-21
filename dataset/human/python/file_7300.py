s=input()
q=int(input())

from collections import deque

deq=deque(s)

cnt=0
for _ in range(q):
    query=input().split()
    if int(query[0])==1:
        cnt+=1
    elif int(query[0])==2:
        if int(query[1])==1:
            if cnt%2==0:
                deq.appendleft(query[2])
            else:
                deq.append(query[2])
        else:
            if cnt%2==0:
                deq.append(query[2])
            else:
                deq.appendleft(query[2])

if cnt%2==0:
    ans=''.join(list(deq))
else:
    ans=''.join(list(deq)[::-1])

print(ans)
