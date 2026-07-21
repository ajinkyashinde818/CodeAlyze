d, g = map(int, input().split())
g = g//100
p = [0] * (d+1)
c = [0] * (d+1)
for i in range(1, d+1):
    p[i], c[i] = map(int, input().split())
    c[i] = c[i]//100

def dfs(h, s):
    if h == 0:
        return 10**9
    tmp = min(p[h], s//h)
    score = tmp * h
    if tmp == p[h]:
        score += c[h]
    if score < s:
        tmp += dfs(h-1, s-score)
    return min(tmp, dfs(h-1, s))

print(dfs(d, g))
