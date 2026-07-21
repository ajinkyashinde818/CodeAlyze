def dfs(i, total, count, left):
    global ans
    if i == d:
        if total < g:
            target = max(left)
            n = min(pc[target - 1][0], -(-(g - total) // (target * 100)))
            count += n
            total += n * target * 100

        if total >= g:
            ans = min(ans, count)

    else:
        dfs(i+1, total, count, left)
        dfs(i + 1, total + pc[i][0] * (i + 1) * 100 + pc[i][1], \
        count + pc[i][0], left - {i + 1})

d,g = map(int, input().split())
pc = [list(map(int, input().split())) for i in range(d)]

ans = float("inf")

dfs(0,0,0,set(range(1,d+1)))
print(ans)
