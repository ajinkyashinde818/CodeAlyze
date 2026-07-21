import math
N, K = map(int, input().split())
P = [i -1 for i in map(int,input().split())]
lgk = int(math.log(K,2))
last = P
point = 0
for j in range(lgk+1):
    if (K >> j) & 1:
        point = last[point]
    res = []
    for i in last:
        res.append(last[i])
    last = res

print(point+1)
