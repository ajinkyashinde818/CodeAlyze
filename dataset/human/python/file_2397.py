D, G = map(int, input().split())
p = [0] * (D + 1)
c = [0] * (D + 1)
for i in range(1, D+1):
    p[i], c[i] = map(int, input().split())
ans = float('inf')


def dfs(i, g):
    global ans
    if i == 0:
        return ans
    cnt = min(g // (100 * i), p[i])
    score = 100 * i * cnt
    if cnt == p[i]:
        score += c[i]
    if g > score:
        cnt += dfs(i - 1, g - score)
    return min(cnt, dfs(i - 1, g))


print(dfs(D, G))
