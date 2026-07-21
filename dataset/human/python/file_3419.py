from collections import Counter


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


res = prime_factorize(int(input()))

counter = Counter(res)
keys = counter.keys()

result = 0
for key in keys:
    items = counter.get(key)

    start = 1

    while items - start >= 0:
        items = items - start
        result += 1
        start += 1

print(result)
