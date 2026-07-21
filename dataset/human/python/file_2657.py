d, g = map(int, input().split())
pc = [tuple(map(int, input().split())) for i in range(d)]


nokori = set(range(1, d+1))


def dfs(i, sum, nokori, cnt):
    global ans
    if i == d:
        if sum < g:
            use = max(nokori)
            n = min(pc[use-1][0], -(-(g-sum)//(use*100)))
            cnt += n
            sum += n * use*100
        if sum >= g:
            ans = min(ans, cnt)
    else:
        dfs(i+1, sum, nokori, cnt)
        dfs(i+1, sum + pc[i][0] * (i+1) * 100 +
            pc[i][1], nokori-{i+1}, cnt+pc[i][0])


ans = float('inf')

dfs(0, 0, nokori, 0)

print(ans)
