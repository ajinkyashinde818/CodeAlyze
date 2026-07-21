def solve():
    R, G, B, N = map(int, input().split())
    ans = 0
    for r in range(N + 1):
        cnt1 = R * r
        if cnt1 > N:
            break
        for g in range(N + 1):
            cnt2 = cnt1 + G * g
            if cnt2 > N:
                break
            if (N - cnt2) % B == 0:
                ans += 1
    print(ans)
solve()
