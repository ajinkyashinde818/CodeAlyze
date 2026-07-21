from functools import lru_cache


def PrimeFactorization(n):
    pf = {}
    i = 2
    while i ** 2 < n:
        while n % i == 0:
            pf[i] = pf.get(i, 0) + 1
            n //= i
        i += 1
    if n > 1:
        pf[n] = 1
    return pf


@lru_cache(maxsize=100000)
def f(x):
    return int((-1 + (1 + 8 * x) ** 0.5) // 2 + 0.001)


def resolve():
    n = int(input())
    d = PrimeFactorization(n)
    ans = 0
    for v in d.values():
        ans += f(v)
    print(ans)


if __name__ == '__main__':
    resolve()
