n,k = map(int, input().split())
a = list(map(int, input().split()))

now=0
cnt=0
from collections import defaultdict
d = defaultdict(lambda: -1)

d[0]=0

while True:
    cnt+=1
    nxt=a[now]-1
    now=nxt
    if k==cnt:
        print(nxt+1)
        exit()
    if d[nxt]!=-1:
        break
    d[nxt]=cnt

k-=d[nxt]
k%=(cnt-d[nxt])

cnt=0
while cnt<k:
    cnt+=1
    nxt=a[now]-1
    now=nxt

print(now+1)
