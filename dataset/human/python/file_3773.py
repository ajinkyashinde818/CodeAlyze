def d():
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

    N = int(input())
    c = collections.Counter(prime_factorize(N))
    ans = 0
    for i in c.values():
        j = 1
        while j <= i:
            i -= j
            ans += 1
            j += 1

    print(ans)


##########
if __name__ == "__main__":
    d()
