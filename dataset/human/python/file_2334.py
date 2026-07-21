import  itertools
d,g=map(int,input().split())
p=[]
c=[]
for i in range(d):
    x,y=map(int,input().split())
    p.append(x)
    c.append(y)
ans=float('inf')
def judge(tmp):
    ss=g
    count=0
    for i in range(d):
        if tmp[i]==1:
            ss-=((i+1)*p[i]*100+c[i])
            count+=p[i]
    if ss<=0:
        return count
    else:
        for i in range(d-1,-1,-1):
            if tmp[i]==0:
                if ss%((i+1)*100)==0:
                    fgh=ss//((i+1)*100)
                else:
                    fgh=1+ss//((i+1)*100)
                if fgh>=p[i]:
                    count+=float('inf')
                else:
                    count+=fgh
                ss -= fgh * ((i + 1) * 100)
            if ss<=0:
                return count
        return count+float('inf')
nums=[0,1]
for sd in itertools.product(nums,repeat=d):
    pat=list(sd)
    sdf=judge(pat)
    ans=min(ans,sdf)
print(ans)
