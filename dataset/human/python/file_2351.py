D,G=map(int,input().split())
pc=[[0,0] for i in range(D)]
ans=[]
for i in range(D):
    pc[i][0],pc[i][1]=map(int,input().split())

def solve(index,total):
    res=0
    g=0
    for i in reversed(range(D)):
        if i in index:
            x=(pc[i][0]-1)*(i+1)*100
            if x<total:
                total-=x
                res+=pc[i][0]-1
            elif x==total:
                res+=pc[i][0]-1
                g=1
                break
            else:
                res+=(pc[i][0]-1)-(x-total)//((i+1)*100)
                g=1
                break
    if g==1:
        return res
    else:
        return 10**20

for i in range(2**D):
    f=0
    index=[]
    total=0
    problem=0
    while 1<<f <= i:
        if i & 1<<f:
            index.append(f)
        f+=1
    for a in reversed(range(D)):
        if not(a in index):
            total+=pc[a][0]*(a+1)*100+pc[a][1]
            problem+=pc[a][0]
    if total<G:
        total=G-total
        ans.append(problem+solve(index,total))
    else:
        ans.append(problem)
print(min(ans))
