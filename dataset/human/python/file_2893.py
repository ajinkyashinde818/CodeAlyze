import sys
from collections import defaultdict

readline = sys.stdin.readline


def prime_factorize(n):
    a = defaultdict(int)
    while n % 2 == 0:
        a[2] += 1
        n //= 2
    f = 3
    while f * f <= n:
        if n % f == 0:
            a[f] += 1
            n //= f
        else:
            f += 2
    if n != 1:
        a[n] += 1
    return a


def isqrt(n):
    if n > 0:
        x = 1 << (n.bit_length() + 1) // 2
        y = (x + n // x) // 2
        while y < x:
            x = y
            y = (x + n // x) // 2
        return x
    elif n == 0:
        return 0
    else:
        raise ValueError("isqrt() argument must be nonnegative")


def main():
    N = int(readline())
    c = prime_factorize(N)

    ans = 0
    for power in c.values():
        ans += (isqrt(1 + 8 * power) - 1) // 2

    print(ans)
    return


if __name__ == '__main__':
    main()
