import math

D,G = map(int, input().split())
l=[list(map(int,input().split())) for i in range(D)]
lst=[[(i+1)*100]*(l[i][0]-1) + [(i+1)*100 + l[i][1]] for i in range(len(l))]
ans = 100*D
dis = 100000*D
for i in range(1<<D):
    point,num,maxp=0,0,0
    for j in range(D):
        if (i>>j)&1:
            num+=len(lst[j])
            point+=sum(lst[j])
        else:
            maxp=j
    if point + (maxp+1)*100*(len(lst[maxp])-1) >= G:
        mq = max(0,math.ceil((G-point)/((maxp+1)*100)))
        ans = min(ans, num+mq)
print(int(ans))
