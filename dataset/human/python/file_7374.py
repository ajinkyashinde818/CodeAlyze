from collections import deque
s=input()
q=int(input())
sd=deque()
for i in range(len(s)):
    sd.append(s[i])
count=0
for i in range(q):
    que=list(map(str,input().split()))
    if int(que[0])==1:
        count+=1
    else:
        if int(que[1])==1:
            if count%2==0:
                sd.appendleft(str(que[2]))
            else:
                sd.append(str(que[2]))
        else:
            if count%2==0:
                sd.append(str(que[2]))
            else:
                sd.appendleft(str(que[2]))
if count%2!=0:
    sd.reverse()

ans=''.join(sd)
print(ans)
