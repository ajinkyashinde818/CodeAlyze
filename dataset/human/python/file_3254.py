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

n = int(input())
c = collections.Counter(prime_factorize(n))
val = list(c.values())

# print(val)
ans = 0
for v in val:
    i = 1
    c = 1
    while v >= c:
        # print(v, c)
        ans += 1
        i += 1
        c += i
print(ans)
