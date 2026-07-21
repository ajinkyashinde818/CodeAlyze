import collections
N = int(input())


def prime_factorize(n):
    a = collections.defaultdict(int)
    while n % 2 == 0:
        a[2] += 1
        n //= 2
    f = 3
    while f * f <= n:
        if n % f == 0:
            a[f] += 1
            n //= f
        else:
            f += 2
    if n != 1:
        a[n] += 1
    return a


ans = 0
for v in prime_factorize(N).values():
    for i in range(1, 100):
        if (i + 1) * (i + 2) // 2 > v:
            break
    ans += i
print(ans)
