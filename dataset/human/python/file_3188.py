n = int(input())


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


def counter(n):

    ccc = 1

    for i in range(2, 16):
        n -= i
        if n < 1:
            return ccc
        else:
            ccc += 1


results = prime_factorize(n)
numbers = {}

for nn in results:
    if nn in numbers.keys():
        numbers[nn] += 1
    else:
        numbers[nn] = 1

output = 0
for v in numbers.values():
    output += counter(v)

print(output)
