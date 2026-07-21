import math
d,g = map(int,input().split())
ans = []
data = []

for i in range(0,d):
    P,C = map(int,input().split())
    data.append((P,C,(i+1)*100))

def dfs(i,sum,a,last):
    if i >= d:
        p,c,point = data[last]
        if sum >= g-(c+p*point):
            global ans
            a += max(0,min(math.ceil((g-sum)/point),p))
            ans.append(a)
        return
    dfs(i+1,sum,a,last)
    p,c,point = data[i]
    if i != last:
        dfs(i+1,sum+c+p*point,a+p,last)

for i in range(0,d):
    p,c,point = data[i]
    dfs(0,0,0,i)
print(min(ans))
