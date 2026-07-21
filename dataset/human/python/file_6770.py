from collections import deque
S=deque(input())
Q=int(input())
re=True
cnt=0
for i in range(Q):
    q=list(map(str,input().split()))
    if q[0]=='1':
        cnt+=1
        if re==True:
            re=False
        else:
            re=True
    else:
        if re==True:
            if q[1]=='1':
                S.appendleft(q[2])
            else:
                S.append(q[2])
        else:
            if q[1]=='2':
                S.appendleft(q[2])
            else:
                S.append(q[2])
if cnt%2==1:
    S.reverse()
print(*S,sep='')
