from collections import deque
S=deque(input())
Q=int(input())
ans=0
for i in range(Q):
    q=input()
    if q[0]=='2':
        if ans%2==0:
            if q[2]=='1':
                S.appendleft(q[4])
            else:
                S.append(q[4])
        else:
            if q[2]=='1':
                S.append(q[4])
            else:
                S.appendleft(q[4])
    else:
        ans+=1
S="".join(S)
print(S if ans%2==0 else S[::-1])
