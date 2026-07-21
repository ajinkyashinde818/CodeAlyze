def makelist(n, m):
    return [[0 for _ in range(m)] for _ in range(n)]


R, G, B, N = map(int, input().split())
ans = 0
for i in range(3001):
    for j in range(3001):
        tmp = N - i*R - G*j
        if tmp >= 0 and tmp % B == 0:
            ans += 1
print(ans)
