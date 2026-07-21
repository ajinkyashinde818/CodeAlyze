from collections import deque
S=input()
Q=int(input())
r_count=0
top=[1,2]
tail=[2,1]
S=deque(list(S))

for i in range(Q):
    q=list(input().split())
    if q[0]=="1":
        r_count+=1
    else:
        q[1]=int(q[1])
        if q[1]==1:
            q[1]=top[r_count%2]
        else:
            q[1]=tail[r_count%2]
        
        if q[1]==1:
            S.appendleft(q[2])
        else:
            S.append(q[2])
S=list(S)
if r_count%2==1:
    S.reverse()
print(''.join(S))
