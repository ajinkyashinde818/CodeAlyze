from collections import deque
s=input()
q=int(input())
turn=0
ans=deque(s)
for i in range(q):
    query=input().split()
    if query[0]=="1":
        turn+=1
    if query[0]=="2":
        if query[1]=="1":
            if turn%2==0:
                ans.appendleft(query[2])
            else:
                ans.append(query[2])
        elif query[1]=="2":
            if turn%2==0:
                ans.append(query[2])
            else:
                ans.appendleft(query[2])
ans="".join(ans)
if turn%2==1:
    ans=ans[::-1]
print(ans)
