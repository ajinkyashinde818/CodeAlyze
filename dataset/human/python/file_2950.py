import sys

sys.setrecursionlimit(10 ** 6)
INF = float("inf")
MOD = 10 ** 9 + 7


def input():
    return sys.stdin.readline().strip()


def factorization(n):
    d = {}
    tmp = n
    for i in range(2, int(n ** 0.5) + 1):
        if tmp % i == 0:
            cnt = 0
            while tmp % i == 0:
                cnt += 1
                tmp //= i
            d[i] = cnt

    if tmp != 1:
        d[tmp] = 1

    return d


def main():
    N = int(input())
    d = factorization(N)
    ans = 0
    for k, v in d.items():
        i = 1
        while v - i >= 0 and N % (k ** i) == 0:
            v -= i
            ans += 1
            N //= k ** i
            i += 1
    print(ans)


if __name__ == "__main__":
    main()
