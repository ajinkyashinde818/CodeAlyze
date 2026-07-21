def get_prime_fact(n):
    primes = []
    append = primes.append
    while n % 2 == 0:
        append(2)
        n //= 2
    f = 3
    while f * f <= n:
        if n % f == 0:
            append(f)
            n //= f
        else:
            f += 2
    if n != 1:
        append(n)
    return primes


def get_knu(a):
    before = 1
    n = 2
    while True:
        knum = (n * (n + 1)) // 2
        if a == knum:
            return n
        elif knum > a > before:
            return n - 1
        else:
            n += 1
            before = knum


D = int(input())
p = get_prime_fact(D)

if len(p) != len(set(p)):
    res = 0
    for n in set(p):
        count = p.count(n)
        if count == 1:
            res += 1
        else:
            add = get_knu(count)
            res += add

    print(res)
else:
    print(len(p))
