def main():
    N = int(input())

    def prime_factorize(n):
        res = []
        for i in range(2, n+1):
            if i*i > n:
                break
            if n % i != 0:
                continue
            ex = 0
            while n % i == 0:
                ex += 1
                n //= i
            res.append((i, ex))
        if n != 1:
            res.append((n, 1))
        return res

    divs = prime_factorize(N)
    ans = 0
    for p, e in divs:
        d = p
        for _ in range(e):
            if N % d != 0:
                break
            N //= d
            d *= p
            ans += 1
    print(ans)


if __name__ == '__main__':
    main()
