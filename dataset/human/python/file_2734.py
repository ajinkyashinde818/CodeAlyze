d,g=map(int,input().split())
pc=[list(map(int,input().split())) for _ in range(d)]

p_num=[]
for p,c in pc:
    p_num.append(p)

ans = 10**9
def dfs(i,cnt,point,rem_ans):
    global ans
    if i == d:
        if point < g:
            use = max(rem_ans)
            n = min(pc[use-1][0], -(-(g-point)//(use*100)))
            cnt += n 
            point += n * use * 100

        if point >= g:
            ans = min(ans,cnt)

    else:
        dfs(i+1,cnt,point,rem_ans)
        dfs(i+1,cnt+pc[i][0],point+pc[i][0]*(i+1)*100 + pc[i][1],rem_ans - {i+1})

dfs(0,0,0,set(range(1,d+1)))    
print(ans)
