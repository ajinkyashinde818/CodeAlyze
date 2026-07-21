import math
 
d,g = [int(i) for i in input().split()]
P = []
C = []
for i in range(d):
    p,c = [int(i) for i in input().split()]
    P.append(p)
    C.append(c)

def flag(point,P,now):
    if point+100*(now+1)*(P-1) >= g: return 1
    elif point+100*(now+1)*P + C[now] >= g: return 2
    else: return 0

m = 10**9
def score(point = 0, n = 0, now=-1, remain = list(range(d))):
    global m
    if m <= n: return
    elif now == -1:
        for i in remain:
            score(point, n, i, remain)
    elif point >= g: m = n
    elif flag(point,P[now],now) == 1:
        n += math.ceil((g-point)/(100*(now+1)))
        if m > n: m = n
    elif flag(point,P[now],now) == 2:
        n += P[now]
        if m > n: m = n
    else:
        if m <= n+P[now]: return
        else:
            remain = remain[:]
            remain.remove(now)
            nxtp = point + P[now]*100*(now+1) + C[now]
            for i in remain:
                score(nxtp, n + P[now], i, remain)

score()
print(m)
