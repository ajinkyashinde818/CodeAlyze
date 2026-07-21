import collections

def prime_fact_counts(n):
    c = collections.Counter(prime_factorize(n))
    return c.values()


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
count = 0
for x in prime_fact_counts(n):
    for i in range(1, x + 1):
        if x >= i:
            x -= i
            count += 1
        else:
            break
print(count)
