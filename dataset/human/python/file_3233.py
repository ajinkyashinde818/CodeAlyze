def resolve():
    import math

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

    n = int(input())
    p = prime_factorize(n)
    if len(p) == 0:
        print(0)
        return

    pn = list(set(p))
    ans = 0
    for m in pn:
        i = 1
        k = p.count(m)
        while(k > 0):
            k -= i
            i += 1
            if k >= 0:
                ans += 1
    print(ans)

resolve()
