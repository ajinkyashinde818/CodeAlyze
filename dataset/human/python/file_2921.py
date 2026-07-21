def abc169_d():

    def prime_factorize(n: int) -> list:
        ''' nの素因数分解 '''
        arr = []
        while n % 2 == 0:
            arr.append(2)
            n = n // 2
        f = 3
        while f * f <= n:
            if n % f == 0:
                arr.append(f)
                n = n // f
            else:
                f += 2
        if n != 1:
            arr.append(n)
        return arr

    N = int(input())
    primes = prime_factorize(N)
    ans = 0

    from collections import Counter
    for _, v in Counter(primes).items():
        u = 1
        while True:
            tmp = (u+2) * (u+1) // 2
            if tmp <= v: u += 1
            else: break
        ans += u
    print(ans)

abc169_d()
