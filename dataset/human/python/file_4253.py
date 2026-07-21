import collections


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


def main():
    n = int(input())
    factor_counts = collections.Counter(prime_factorize(n))

    result = 0

    for _, c in factor_counts.items():
        current_c = c
        n = 1
        while current_c >= n:
            current_c = current_c - n
            result += 1
            n += 1

    print(result)


if __name__ == "__main__":
    main()
