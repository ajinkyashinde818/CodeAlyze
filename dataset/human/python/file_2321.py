def min2(x,y):
    return x if x < y else y

from math import ceil
D, G = map(int, input().split())
P = []
C = []
for _ in range(D):
    p, c = map(int, input().split())
    P.append(p)
    C.append(c)
res = float("inf")
for bit in range(1<<D):
    temp = 0
    cnt = 0
    for i in range(D):
        if (bit>>i)&1:
            temp += 100*(i+1)*P[i]+C[i]
            cnt += P[i]
    if temp >= G:
        res = min2(res, cnt)
        continue
    for i in reversed(range(D)):
        if not (bit>>i)&1:
            k = ceil((G-temp)/(100*(i+1)))
            if k >= P[i]:
                temp += 100*(i+1)*(P[i]-1)
                cnt += P[i]-1
            else:
                cnt += k
                res = min2(res, cnt)
                break
print(res)
