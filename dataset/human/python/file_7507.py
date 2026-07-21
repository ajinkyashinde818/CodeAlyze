from collections import deque

N = deque(input())
Q = int(input())
Qs = []
for _ in range(Q):
    Qs.append(list(map(str, input().split())) ) 
k=0
for q in Qs:
    if q[0] == '1':
        k+=1
    else:
        if k%2 ==0:
            if q[1]=='1':
                N.appendleft(q[2])
            else:
                N.append(q[2])
        else:
            if q[1]=='2':
                N.appendleft(q[2])
            else:
                N.append(q[2])
if k%2==1:
    ans=''
    for x in reversed(N):
        ans += x
else:
    ans=''
    for x in N:
        ans += x

print(ans)
