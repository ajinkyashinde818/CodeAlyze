from collections import deque
s=input()
q=int(input())

flug=0
ans=deque(list(s))

for i in range(q):
    t=list(input().split())

    if t[0]=="1":
        flug+=1
    else:
        if (flug%2==0 and t[1]=="2") or (flug%2==1 and t[1]=="1"):
            ans.append(t[2])
        else:
            ans.appendleft(t[2])

ans="".join(map(str,ans))

if flug%2==1:
    ans=ans[::-1]
print(ans)
