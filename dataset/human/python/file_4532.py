N = int(input())

if N == 1:
    print(0)
    exit()

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

import collections
c = collections.Counter(prime_factorize(N))

# print(c)
ans = 0
for key in c.keys():
    i = 1
    while True:
        c[key] -= i
        ans += 1
        i += 1
        if c[key] < i:
            break

print(ans)
