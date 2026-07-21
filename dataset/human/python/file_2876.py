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
ans = 0
N = int(input())
c = collections.Counter(prime_factorize(N))
for i in c.values():
    j = 1
    while True:
        i -= j
        j += 1
        ans += 1
        if i - j < 0:
            break
print(ans)
