d,g=map(int,input().split())
plist=[]
clist=[]
for i in range(d):
    p,c=map(int,input().split())
    plist.append(p-1)
    clist.append(c)
def f(pl,goal):
    result=0
    if goal<0:
        return 0
    for i in range(d,0,-1):
        if goal>=pl[i-1]*(i)*100:
            result+=pl[i-1]
            goal-=pl[i-1]*(i)*100
        else:
            if goal%((i)*100)==0:
                result+=goal//((i)*100)
                goal=0
                break
            
                
            result+=goal//((i)*100)+1
            goal=0
            break
    if goal>0:
        return 1000
    return result
blist=[list(str(bin(i)))[2:][-1::-1]for i in range(2**d)]
result=1000
    
for c in blist:
    qlist=plist[:]
    h=g
    ires=0
    for i in range(len(c)):
        if c[i]=='1':
            qlist[i]=0
            h-=clist[i]+(plist[i]+1)*(i+1)*100
            ires+=plist[i]+1
    result=min([result,f(qlist,h)+ires])
print(result)
