from collections import deque
S=deque(input())
ans=""
Q=int(input())
tmp=0
r=[]
l=[]

for i in range(Q):
    que=input().split()
    if que[0]=='1':
        tmp=1-tmp
    if que[0]=='2':
        if que[1]=='1':
            if tmp==0:
                #S=que[2]+S
                #l.append(que[2])
                #ans=ans+que[2]
                S.appendleft(que[2])
            else:
                #S=S+que[2]
                #r.append(que[2])
                #ans=que[2]+ans
                S.append(que[2])
        else:
            if tmp==0:
                #S=S+que[2]
                #r.append(que[2])
                #ans=que[2]+ans
                S.append(que[2])
            else:
                #S=que[2]+S
                #l.append(que[2])
                #ans=ans+que[2]
                S.appendleft(que[2])
#print(que)
"""
for i in range(Q):
    if que[i][0]=='1':
        tmp=1-tmp
    if que[i][0]=='2':
        if que[i][1]=='1':
            if tmp==0:
                S=que[i][2]+S
            else:
                S=S+que[i][2]
        else:
            if tmp==0:
                S=S+que[i][2]
            else:
                S=que[i][2]+S
"""
#print(tmp)
"""
for i in range(len(r)):
    S=S+r[i]
    ans=r[i]+ans
for i in range(len(l)):
    S=l[i]+S
    ans=ans+l[i]
"""
if tmp==1:
    print("".join(reversed(S)))
    exit()

print("".join(S))
