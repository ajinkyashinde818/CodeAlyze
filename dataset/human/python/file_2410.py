import math
d,g = map(int,input().split())
g //= 100
p = [0 for _ in range(d)]
c = [0 for _ in range(d)]
sump = [0 for _ in range(d)]
for i in range(d):
    p[i],c[i] = map(int,input().split())
    c[i] = c[i]//100
    sump[i] = (i+1)*p[i] + c[i]

min = 10000


for i in range(1<<d):
    sum = 0
    qst = 0
    maxq = 1
    for j in range(d):
        if i>>j & 1:
            sum += sump[j]
            qst += p[j]
        elif maxq < j+1:
            maxq = j+1
    if sum + maxq*p[maxq-1] < g:
        continue
    else:
        if min > max(0,math.ceil((g-sum)/maxq)) + qst:
            min = max(0,math.ceil((g-sum)/maxq)) + qst

print(min)
