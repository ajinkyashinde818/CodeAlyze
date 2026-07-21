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


def how_many_times(p):
    i = 0
    while True:
        if i * (i + 1) // 2 > p:
            break
        i += 1

    return i - 1


n = int(input())
factors = Counter(prime_factorize(n))

ans = 0
for f, p in factors.items():
    ans += how_many_times(p)

print(ans)
