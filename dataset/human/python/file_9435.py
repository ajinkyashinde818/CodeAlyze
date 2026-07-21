from collections import defaultdict

n, k = map(int,input().split())
a = list(map(int,input().split()))

route = defaultdict(int)
i = 0
loop = []
tail = []

while route[i] < 2:

    if route[i] == 0:
        tail.append(i)
    else:
        loop.append(i)
    
    route[i] += 1
    i = a[i] - 1

if len(tail) > k:
    print(tail[k] + 1)
else:
    temp = len(tail) - len(loop)
    print(loop[(k-temp) % len(loop)] + 1)
