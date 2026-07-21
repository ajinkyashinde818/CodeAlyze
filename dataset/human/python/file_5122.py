from collections import deque
n,m=map(int,input().split())
ab=[[] for _ in range(n+1)]
for i in range(m):
    a,b=map(int,input().split())
    ab[a].append(b)
    ab[b].append(a)
que=deque()
que.append(1)
count=[0]*2+[-1]*(n-1)
while que:
    x=que.pop()
    for j in ab[x]:
        if count[j]==-1:
            count[j]=count[x]+1
            que.appendleft(j)
if count[n]==2:
    print("POSSIBLE")
else:
    print("IMPOSSIBLE")
