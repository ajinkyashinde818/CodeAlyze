from collections import deque
s=input()
q=int(input())
rev=0
head=deque()
tail=deque()
for _ in range(q):
    Q=input().split()
    if len(Q)==1:
        rev=1-rev
    if len(Q)==3:
        if(rev==0 and Q[1]=="1" )or (rev==1 and Q[1]=="2"):
            head.appendleft(Q[2])
        else :
            tail.append(Q[2])
if rev==0:
    ans="".join(head)+s+"".join(tail)

else:
    ans="".join(tail)[::-1]+s[::-1]+"".join(head)[::-1]

print(ans)
