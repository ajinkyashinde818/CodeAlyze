def dfs (i,sum,count,rem):
    global ans
    if i == D:
        if sum < G:
            k = max(rem)
            n = min(pc[k-1][0],-(-(G-sum)//(k*100)))
            count += n
            sum += n*100*k
        if sum >= G:
            ans = min(ans,count)
    else:
        dfs(i+1,sum,count,rem)
        dfs(i+1,sum+pc[i][0]*100*(i+1)+pc[i][1],count+pc[i][0],rem-{i+1})

D,G = map(int,input().split())
pc = [list(map(int,input().split())) for i in range(D)]

ans = float("inf")

dfs(0,0,0,set(range(1,D+1)))
print(ans)
