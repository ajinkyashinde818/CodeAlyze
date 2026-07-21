import itertools
d,c=map(int, input().split())
p=[list(map(int, input().split())) for i in range(d)]
al=list(itertools.product(range(2),repeat=d))
ans=1000
for i in al:
    count=0
    score=0
    if 0 not in i:continue
    last0=d-list(reversed(i)).index(0)-1
    for j in range(d):
        count+=i[j]*p[j][0]
        score+=i[j]*p[j][1]+i[j]*p[j][0]*(j+1)*100
    #print(count,score,last0,i)
    if score>=c:ans=min(ans,count)
    elif (c-score)/((last0+1)*100)<p[last0][0]:ans=min(ans,count+(c-score+last0*100)//((last0+1)*100))
if d==1:print(1)
else:print(ans)
