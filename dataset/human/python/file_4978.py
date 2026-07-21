import sys

readline = sys.stdin.readline
MOD = 10 ** 9 + 7
INF = float('INF')
sys.setrecursionlimit(10 ** 5)


def main():
    N = int(readline())
    X = list(map(int, readline().split()))

    mul_mod = [0] * N

    cur = 1
    for i in range(1, N):
        cur *= i
        cur %= MOD
    mul_mod[1] = cur

    for i in range(2, N):
        mul_mod[i] = (mul_mod[1] * pow(i, MOD - 2, MOD)) % MOD

    p = [0] * (N - 1)
    p[-1] = sum(mul_mod[1:N]) % MOD

    for i in range(2, N):
        p[-i] = p[-i + 1] - mul_mod[N - i + 1]
        p[-i] %= MOD

    ans = 0

    for i in range(N - 1):
        ans += (X[i + 1] - X[i]) * p[i]
        ans %= MOD

    print(ans)


if __name__ == '__main__':
    main()
