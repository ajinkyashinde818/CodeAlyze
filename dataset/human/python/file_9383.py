from collections import deque

N,k = map(int,input().split())

a = list(map(int,input().split()))

d = [-1] * N
d[0] = 0
q = deque()
q.append(1)

while(q):
    x = q.popleft()
    n = a[x - 1]
    if(d[n-1] == -1):
        d[n-1] = d[x-1] + 1
        q.append(n)

if(k <= max(d)):
    for i in range(N):
        if(d[i] == k):
            print(i+1)
            exit()


rS = n

d2 = [-1] * N
d2[rS - 1] = 0
q = deque()
q.append(rS)

while(q):
    x = q.popleft()
    n = a[x - 1]
    if(d2[n-1] == -1):
        d2[n-1] = d2[x-1] + 1
        q.append(n)
ma = max(d2) + 1
k -= d[rS - 1]
k %= ma

for i in range(N):
    if(d2[i] == k):
        print(i+1)
        exit()
