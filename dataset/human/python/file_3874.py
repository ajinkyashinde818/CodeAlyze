def main():
    import sys
    sys.setrecursionlimit(10**9)
    input = sys.stdin.readline

    N = int(input())

    if N == 1:
        print(0)
        return

    def prime_factorization(n):
        from collections import Counter
        p = Counter()
        while n % 2 == 0:
            p[2] += 1
            n //= 2

        i = 3
        while i*i <= n:
            if n % i == 0:
                p[i] += 1
                n //= i
            else:
                i += 2

        if n != 1:
            p[n] += 1

        return p

    d = prime_factorization(N)

    ans = 0
    for i in d:
        tmp = 1
        for j in range(d[i]):
            tmp *= i
            if N % tmp == 0:
                ans += 1
                N //= tmp
            else:
                break
            if N == 1:
                break
        if N == 1:
            break

    print(ans)

main()
