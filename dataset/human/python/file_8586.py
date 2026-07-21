import bisect
K, N = map(int, input().split())
a = list(map(int, input().split()))

ans = min(a[-1] - a[0], K - a[-1] + a[-2])
for i in range(1, N - 1):
    ans = min(ans, K - a[i] + a[i - 1])

print(ans)
