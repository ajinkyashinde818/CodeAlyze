from collections import Counter


def prime_factorize(n):
    a = []
    while n % 2 == 0:
        a.append(2)
        n //= 2
    f = 3
    while f * f <= n:
        if n % f == 0:
            a.append(f)
            n //= f
        else:
            f += 2
    if n != 1:
        a.append(n)
    return a


def div_count(primes: dict) -> int:
    cnt = 0
    for _, c in primes.items():
        i = 1
        while True:
            if c < i:
                break
            cnt += 1
            c -= i
            i += 1

    return cnt


if __name__ == "__main__":
    n = int(input())
    primes = Counter(prime_factorize(n))
    print(div_count(primes))
