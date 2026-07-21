from collections import Counter

N = int(input())

def prime_factorize(n):
    a = []
    while n % 2 == 0:
        a.append(2)
        n //= 2
    f = 3
    while f * f <= n:
        if n % f == 0:
            a.append(f)
            n /= f
        else:
            f += 2
    if n != 1:
        a.append(n)
    return a

c = Counter(prime_factorize(N))
n = 0
for prime in c:
    wa = 1
    count = 1
    length = c[prime]
    while True:
        if c[prime] >= wa:
            n += 1
            count += 1
            wa += count
        else:
            break
print(n)
