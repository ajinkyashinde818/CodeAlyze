from collections import deque
s=input()
q=int(input())
n=0
que=deque(s)
for i in range(q):
    l=input()
    if l[0]=='1':
        n+=1
    else:
        if (l[2]=='1' and n%2==0) or (l[2]=='2' and n%2==1):
            que.appendleft(l[4])
        else:
            que.append(l[4])

ans=''.join(que)
if n%2==0:
    print(ans)
else:
    print(ans[::-1])
