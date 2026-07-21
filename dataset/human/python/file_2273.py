def dfs(i, total, S, remain):
    global ans
    if i == D:
        if S < G:
           use = max(remain)
           N = min(L[use-1][0], -(-(G-S)//(100*use)))
           S += 100 * N * use
           total += N
           
        if S >= G:
           ans = min(ans, total)
    else:
        dfs(i+1, total, S, remain)
        dfs(i+1, total + L[i][0], S + 100 * (i+1) * L[i][0] + L[i][1], remain - {i+1})

D, G = map(int, input().split())
L = [list(map(int, input().split())) for _ in range(D)]
ans = 10 ** 9

dfs(0, 0, 0, set(range(1, D+1)))

print(ans)
