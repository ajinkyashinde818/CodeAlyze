from collections import deque

S=input()
Q=int(input())

R=0
S=deque(S)

for i in range(Q):
    temp=list(input().split())
    if int(temp[0])==1:
        R+=1
    elif int(temp[0])==2:
        F=int(temp[1])
        c=temp[2]
        if F==1:
            if R%2==0:
                S.appendleft(c)
            else:
                S.append(c)
        elif F==2:
            if R%2==0:
                S.append(c)
            else:
                S.appendleft(c)

if R%2==1:
    S=list(S)
    ans=S[-1::-1]
    ans=map(str,ans)
else:
    ans=map(str,S)

print("".join(ans))
