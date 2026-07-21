d , g = map(int, input().split())
pc = [list(map(int, input().split()))for i in range(d)]
x=[]
y=[0]*d
ac=[0]*d
for i in range(d):
    ac[i]=pc[i][0]*(i+1)*100+pc[i][1]

def dfs(n,m,y,now):
    if now==n:
        z=y.copy()
        x.append(z)
        return
    for i in range(m):
        y[now]=i
        dfs(n,m,y,now+1)
dfs(d,3,y,0)
mi = 1000
for i in x:
    sum = 0
    cost = 0
    stock = []
    sum2 = 0
    cost2 = 0
    for j in range(d):
        if i[j]==1:
            sum+=ac[j]
            cost+=pc[j][0]
            sum2+=ac[j]
            cost2+=pc[j][0]
        if i[j]==2:
            stock+=[(j+1)*100]*pc[j][0]
            sum2+=pc[j][0]*(j+1)*100
            cost2+=pc[j][0]
    if sum2<g:
        continue
    stock.sort()
    if abs(sum2-g)>abs(sum-g):
        while sum<g and stock:
            sum+=stock.pop()
            cost+=1
        if sum>=g:
            mi=min(mi,cost)
    else:
        while sum2>g and stock:
            sum2-=stock.pop()
            cost2-=1
        cost+=1
        mi=min(mi,cost2)

print(mi)
