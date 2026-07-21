def dfs(i: int, sum: int, count: int, nokori: int) -> int:
    global ans
    if i == d:
        if sum < g:
            use = max(nokori)
            n = min(p[use], -(-(g-sum) // (use*100)))
            count += n
            sum += n * use * 100

        if sum >= g:
            ans = min(ans, count)
    
    else:
        dfs(i+1, sum, count, nokori)
        dfs(i+1, sum + p[i+1]*(i+1)*100+c[i+1], count + p[i+1], nokori - {i+1})

d,g = map(int, input().split())
p = [0] * (d+1)
c = [0] * (d+1)

for i in range(1, d+1):
    p[i], c[i] = map(int, input().split())

ans = float("inf")

dfs(0, 0, 0, set(range(1, d+1)))
print(ans)
