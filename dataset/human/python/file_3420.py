from collections import Counter


def pf(n):
    primes = Counter()
    c = 2
    while n // c > 0:
        if c**2 > n:
            primes[n] += 1
            break
        while n % c == 0:
            primes[c] += 1
            n //= c
        c += 1
    return primes


def count(t):
    n = 0
    ret = 0
    while True:
        if n * (n + 1) // 2 <= t < (n + 1) * (n + 2) // 2:
            ret = n
            break
        n += 1
    return ret


def main():
    N = int(input())
    primes = pf(N)
    print(sum(list(map(count, primes.values()))))


if __name__ == '__main__':
    main()
