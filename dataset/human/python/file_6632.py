from collections import deque

s=input()
q=int(input())

R=True
ans=deque(list(s))
count=0
for i in range(q):
    l=list(map(str,input().split()))
    if int(l[0])==1:
        if R:
            R=False
        else:
            R=True
        count+=1
    else:
        f,c=int(l[1]),l[2]
        if f==1 and R:
            ans.appendleft(c)
        elif f==2 and R:
            ans.append(c)
        elif f==1 and (not R):
            ans.append(c)
        elif f==2 and (not R):
            ans.appendleft(c)

if count%2==0:
    print(''.join(ans))
else:
    print(''.join(reversed(ans)))
