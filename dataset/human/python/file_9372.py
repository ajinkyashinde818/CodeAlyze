n, k = map(int,input().split())
a = list(map(int,input().split()))
from collections import deque

ans = deque()
ans.appendleft(1)
count = 1
s = -1
zeros = [0]*n

while True:
    if zeros[a[count-1]-1] == 1:
        s = a[count-1]
        break
    else:
        ans.append(a[count-1])
        zeros[count-1]=1
        count = a[count-1]

ans = list(ans)
if s == -1:
    print(ans[k])
else:
    t = ans.index(s)
    if t >= k:
        print(ans[k])
    else:
        ans = ans[t:]
        print(ans[(k-t)%len(ans)])
