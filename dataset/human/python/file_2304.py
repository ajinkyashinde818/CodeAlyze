D, G = map(int, input().split())
p = [list(map(int, input().split())) for _ in range(D)]
plst = [0] * D
ans = 0
for i in range(D):
    ans += p[i][0]

def dfs(n):
    global ans
    if n == D:
        cnt = 0
        total = 0
        for i in range(D):
            if plst[i] == 0:
                continue
            elif plst[i] == 1:
                cnt += p[i][0]
                total += (100 * (i + 1) * p[i][0]) + p[i][1]
        if total < G:
            for j in range(D - 1, -1, -1):
                if plst[j] == 0:
                    for k in range(p[j][0] - 1):
                        total += (100 * (j + 1))
                        cnt += 1
                        if total >= G:
                            break
                    break
            if total >= G:
                ans = min(ans, cnt)
        else:
            ans = min(ans, cnt)
        return

    for i in range(2):
        plst[n] = i
        dfs(n + 1)
    return

dfs(0)
print(ans)
