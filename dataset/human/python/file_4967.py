def solve():
    MOD = 10**9 + 7

    N = int(input())
    xs = list(map(int, input().split()))

    ds = []
    for i in range(N-1):
        d = xs[i+1] - xs[i]
        ds.append(d)

    nums = [1, 1]
    num = 1
    for i in range(2, N-1):
        num *= i
        num %= MOD
        nums.append(num)

    ms = [N-1]
    m = N-1
    for i in reversed(range(2, N-1)):
        m *= i
        m %= MOD
        ms.append(m)
    ms.reverse()
    ms.append(1)

    ks = []
    k = 0
    for num, m in zip(nums, ms):
        k += num*m % MOD
        k %= MOD
        ks.append(k)

    ans = 0
    for d, k in zip(ds, ks):
        ans += d*k % MOD
        ans %= MOD

    print(ans)

solve()
