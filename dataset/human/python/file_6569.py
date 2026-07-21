import sys
input = sys.stdin.readline
from collections import deque

S = input()[:-1]
Q = int(input())
que = []
acc = [0]

for i in range(Q):
    l = list(input().split())
    ty = int(l[0])
    
    if ty==1:
        acc.append(acc[-1]+1)
    else:
        acc.append(acc[-1]+0)
        
    if ty==1:
        continue
        
    f = int(l[1])
    que.append((i, f, l[2]))
    
ans = deque([])

if (acc[-1]-acc[0])%2==0:
    for i in range(len(S)):
        ans.append(S[i])
else:
    for i in range(len(S)-1, -1, -1):
        ans.append(S[i])

for i, f, c in que:
    cnt = acc[-1]-acc[i]
    
    if cnt%2==0:
        if f==1:
            ans.appendleft(c)
        else:
            ans.append(c)
    else:
        if f==1:
            ans.append(c)
        else:
            ans.appendleft(c)

ans = list(ans)
print(''.join(ans))
