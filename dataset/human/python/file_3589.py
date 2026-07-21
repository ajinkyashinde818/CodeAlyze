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
count = 0
j = 1

c = collections.Counter(prime_factorize(N))
factor_sets = list(c.items())

fac_num = len(factor_sets)

for i in range(fac_num):
    while True:
        if (j + 1) * (j + 2) / 2 <= factor_sets[i][1]:
            j += 1
        else:
            count += j
            j = 1
            break

print(count)
