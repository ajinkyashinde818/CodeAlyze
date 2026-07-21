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

N = int(input())
from collections import Counter

def check(v):
    an = 0
    i = 1
    subsum = 0
    while v - subsum >= i:
        subsum += i
        i += 1
        an += 1
    return an

# print(check(16))

def Main(N):
    p = prime_factorize(N)
    c = Counter(p)
    ans = 0
    for v in c.values():
        ans += check(v)
    return ans

print(Main(N))
