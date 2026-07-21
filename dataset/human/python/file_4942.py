def ext_euc(a, b):
    if b == 0:
        return 1, 0, a
    y, x, v = ext_euc(b, a % b)
    y -= (a // b) * x
    return x, y, v


def mod_inv(a, mod):
    x, _, _ = ext_euc(a, mod)
    return x % mod


def mod_fac(a, mod):
    ret = 1
    for aa in range(1, a + 1):
        ret *= aa
        ret %= mod
    return ret


def main():
    MOD = 10**9 + 7
    N = int(input())
    X = list(map(int, input().split()))
    ans = 0
    for n in range(N - 1):
        ans += (X[N - 1] - X[n]) * mod_inv(n + 1, MOD)
    ans *= mod_fac(N - 1, MOD)
    print(ans % MOD)


if __name__ == '__main__':
    main()
