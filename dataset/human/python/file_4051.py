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

primes = prime_factorize(N)

num = 0
hist = [1]
c = 1

tmp = 1
for p in primes:
    # 前回と異なる場合
    if tmp != p:
        c = 1
    tmp = p
    c *= p
    if c not in hist:
        hist.append(c)
        num += 1
        c = 1
print(num)
