import collections
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
c = collections.Counter(prime_factorize(n))
v = list(c.values())
ans = 0
for i in v:
    j = 1
    p = 0
    count = 0
    while True:
        p += j
        j += 1
        if i<p:
            break
        count += 1
    ans += count
print(ans)
