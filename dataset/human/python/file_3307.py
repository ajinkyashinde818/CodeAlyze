import math
def c(x):
    global yaku
    now=x
    for i in range(2,int(math.sqrt(now))+1):
        while now%i==0:
            if i in sosu.keys():
                v=sosu[i]
                sosu[i]=v+1
            else:
                sosu[i]=1
            now=now//i
            yaku+=1
    if(now!=1):
        sosu[now]=1
        yaku+=1
def d(x):
    global ans
    q=x
    cur=1
    while(q>0):
        q=q-cur
        if q>=0:
            ans+=1
        cur+=1
    
n=int(input())
sosu={}
yaku=0
c(n)
if n==1:
    print(0)
else:
    if(yaku==1):
        print(1)
    else:
        ans=0
        #print(sosu)
        for i in sosu.keys():
            d(sosu[i])
        print(ans)
