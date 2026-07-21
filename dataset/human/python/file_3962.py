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


n = int(input().strip())
c = collections.Counter(prime_factorize(n))
ans = 0
for elem in c.items():
    count = 1
    value = elem[1]
    while True:
        value -= count
        count += 1
        ans += 1
        if value < count:
            break
print(ans)
