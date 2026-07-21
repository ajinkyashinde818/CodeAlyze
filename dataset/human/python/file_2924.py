from collections import Counter


def prime_factorize(n):
    A = []
    while n % 2 == 0:
        A.append(2)
        n //= 2

    f = 3
    while f * f <= n:
        if n % f == 0:
            A.append(f)
            n //= f
        else:
            f += 2

    if n != 1:
        A.append(n)

    return A


def main():
    n = int(input())

    A = prime_factorize(n)
    AC = Counter(A)

    ans = 0
    for v in AC.values():
        k = 1
        while True:
            v -= k
            if v < 0:
                break

            ans += 1
            k += 1

    print(ans)


if __name__ == '__main__':
    main()
