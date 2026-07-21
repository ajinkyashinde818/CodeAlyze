MOD = 10**9 + 7

def MOD_perm(n, r):
    rtn = 1
    for _ in range(r):
        rtn *= n
        rtn %= MOD
        n -= 1
    return rtn

def MOD_inv(a):
    b = MOD
    u = 1
    v = 0
    while b > 0:
        t = a // b
        a -= t * b
        a, b = b, a
        u -= t * v
        u, v = v, u
    u = u % MOD
    if u < 0:
        u += MOD
    return u

def main():
    n = int(input())
    x = list(map(int, input().split()))
    ans = 0
    inv = 0
    perm = MOD_perm(n-1, n-1)
    for i in range(1, n):
        dif = x[i] - x[i-1]
        inv += MOD_inv(i)
        inv %= MOD
        ans += dif * perm * inv
        ans %= MOD
    print(ans % MOD)

if __name__ == "__main__":
    main()
