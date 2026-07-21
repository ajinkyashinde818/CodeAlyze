import math

d,gg = map(int,input().split())

p,c = [],[]

for i in range(d):
    pp,cc = map(int,input().split())
    p.append(pp)
    c.append(cc)

ans = 1145141919
for i in range(1 << d):
    g = gg
    cnt = 0
    sum = 0
    for j in range(d):
        if (1 << j) & (i):
            sum += (p[j]*(1+j)*100+c[j])
            cnt += p[j]
    
    g -= sum
    if (g <= 0) : 
        ans = min(ans,cnt)
        continue
    for j in list(reversed(range(d))):
        if (1 << j) & (i) == 0:
            aa = math.ceil(g/((1+j)*100))
            g -= ((1+j)*100)*min(aa,p[j]-1)
            cnt += min(aa,p[j]-1)
            break
    if (g <= 0) : ans = min(ans,cnt)

print(ans)
