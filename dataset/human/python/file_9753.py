from collections import defaultdict
n,k = map(int, input().split())
a = list(map(lambda z:int(z)-1, input().split()))
if k <= n:
    now = 0
    for i in range(k):
        now = a[now]
    print(now+1)
    exit()
root = [0]
use = [-1 for _ in range(n)]
use[0] = 0
now = 0
l = -1
for i in range(1,n+1):
    now = a[now]
    if use[now] == -1:
        use[now] = i
    else:
        k -= i
        l = i - use[now]
        break
k %= l
for i in range(k):
    now = a[now]
print(now+1)
