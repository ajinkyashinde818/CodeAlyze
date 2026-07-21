from collections import deque

mae = deque()
usiro=deque()

s=input()
kai=int(input())

siji=[]*kai

for i in range(kai):
    siji.append(input())


state=1
for i in range(kai):
    si=siji[i]
    if(si[0]=='1'):
        state*=-1
    else:
        _,f,c=si.split()
        f=int(f)
        if(state==-1):
            f=3-f
        if(f==1):
            mae. appendleft(c)
        else:
            usiro.append(c)

ans=deque()
for m in mae:
    if(state==1):
        ans.append(m)
    else:
        ans.appendleft(m)
for smoji in s:
    if(state==1):
        ans.append(smoji)
    else:
        ans.appendleft(smoji)
for u in usiro:
    if(state==1):
        ans.append(u)
    else:
        ans.appendleft(u)

kotae="".join(ans)
print(kotae)
