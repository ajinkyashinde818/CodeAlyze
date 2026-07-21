from collections import defaultdict
n,k=map(int,input().split())
a=list(map(int,input().split()))

order = []
now = 1
count = 0
d = defaultdict(int)


for i in range(n):
    if d[now]!=0:
        s=d[now]-1
        g=i
        break
    order.append(now)
    d[now] = i+1
    now = a[now-1]


if k<=s:
    print(order[k])
else:
    k-=s
    loop = order[s:g]
    print(loop[k%len(loop)])
