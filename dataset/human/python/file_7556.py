from collections import deque
s=deque(list(input()))
p=0
for i in range(int(input())):
    a=list(map(str,input().split()))
    if len(a)==1:
        p^=1
    else:
        if p%2:
            if a[1]=="2":
                s.appendleft(a[2])
            else:
                s.append(a[2])
        else:
            if a[1]=="1":
                s.appendleft(a[2])
            else:
                s.append(a[2])
ans=""
if p%2==1:
    while s:
        ans+=s.pop()
else:
    while s:
        ans+=s.popleft()
print(ans)
