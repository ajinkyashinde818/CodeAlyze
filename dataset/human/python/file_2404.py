def makelist(n, m):
    return [[0 for _ in range(m)] for _ in range(n)]

D, G = map(int, input().split())
p = [0]*(D+1)
c = [0]*(D+1)
for i in range(1, D+1):
    p[i], c[i] = map(int, input().split())


#
ans = int(1e18)
for pat in range(1<<D):
    score = G
    res = 0
    for i in range(1, D+1):
        if pat & (1<<(i-1)) > 0:
            res += p[i]
            score -= i * p[i] * 100 + c[i]
    
    for i in reversed(range(1, D+1)):
        if score <= 0:
            ans = min(ans, res)
            break
        if pat & (1<<(i-1)) == 0:
            now = (score + (i * 100) - 1) // (i * 100)
            if now <= p[i]:
                res += now
                ans = min(ans, res)
                break
            else:
                res += p[i]
                score -= i*100 * p[i]
print(ans)
