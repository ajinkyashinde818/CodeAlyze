import sys

readline = sys.stdin.readline
MOD = 10 ** 9 + 7
INF = float('INF')
sys.setrecursionlimit(10 ** 5)


def factorization(n):
    factors = []

    if n < 2:
        return n

    while n % 2 == 0:
        factors.append(2)
        n //= 2

    for i in range(3, int(n ** 0.5) + 5, 2):
        while n % i == 0:
            factors.append(i)
            n //= i

    if n != 1:
        factors.append(n)

    return factors


def main():
    from collections import Counter

    n = int(input())

    if n == 1:
        print(0)
        sys.exit()

    factors = Counter(factorization(n))

    ans = 0
    i = 0
    flag = True

    while flag:
        flag = False
        i += 1
        for key in factors.keys():
            if factors[key] >= i:
                ans += 1
                factors[key] -= i
                flag = True

    print(ans)


if __name__ == '__main__':
    main()
