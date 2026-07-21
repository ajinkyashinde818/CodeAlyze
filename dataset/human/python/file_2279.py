import math
D,G = map(int,input().split())
PC = [list(map(int,input().split())) for _ in range(D)]

def dfs(d,flag,point,count,tmp):
    point += flag * (PC[d-1][1]+PC[d-1][0]*d*100)
    count += flag * (PC[d-1][0])
    if flag == 0:
        tmp = d
    if d == D:
        if point < G:
            r = math.ceil((G-point)/(tmp*100))
            if r < PC[tmp-1][0]:
                res = count + r
            else:
                res = float("INF")
        else:
            res = count
        return res

    else:
        return min(dfs(d+1,1,point,count,tmp),dfs(d+1,0,point,count,tmp))

print(min(dfs(1,0,0,0,0),dfs(1,1,0,0,0)))
