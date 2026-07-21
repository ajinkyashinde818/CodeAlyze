ans=1000000000
d,g=map(int,input().split())
p=[];c=[]
for i in range(d):
    P,C=map(int,input().split())
    p.append(P);c.append(C)
def search(i,sm,cnt,mx):
    global ans,d,g,p,c
    if(i==d):
        if(sm<g):
            for i in range(p[mx]-1):
                sm+=100*(mx+1)
                cnt+=1
                if(sm>=g):
                    ans=min(ans,cnt)
                    break
        else:
            ans=min(ans,cnt)
        return;
    search(i+1,sm,cnt,i)
    search(i+1,sm+(i+1)*100*p[i]+c[i],cnt+p[i],mx)

search(0,0,0,0)
print(ans)
