from collections import deque
S=input()
d=deque()
for i in S:
    d.append(i)
Q=int(input())
Flag=True
for i in range(Q):
    L=input().split()
    if L[0]=="1":
        Flag=not Flag
    else:
        if L[1]=="1" and Flag or L[1]=="2" and not Flag:
            d.appendleft(L[2])
        else:
            d.append(L[2])
ans=""
for i in d:
    ans+=i
if not Flag:
    ans=ans[::-1]
print(ans)
