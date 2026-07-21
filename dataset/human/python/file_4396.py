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
            n //= f
        else:
            f += 2
    if n != 1:
        a.append(n)
    return a


pri = prime_factorize(N)
c = Counter(pri)
val = list(c.values())

count = 0
for v in val:
    for i in range(1, v+1):
        if v >= i:
            v -= i
            count += 1
        else:
            break
print(count)
