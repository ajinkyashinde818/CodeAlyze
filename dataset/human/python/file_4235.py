from collections import Counter

def prime_factorize(n):
    res = []
    while n % 2 == 0:
        res.append(2)
        n //= 2
    f = 3
    while f * f <= n:
        if n % f == 0:
            res.append(f)
            n //= f
        else:
            f += 2
    if n != 1:
        res.append(n)
    return res

n = int(input())
prime_numbers = prime_factorize(n)
prime_counter = Counter(prime_numbers)

ans = 0
for v in prime_counter.values():
    i = 1
    while v >= i:
        ans += 1
        v -= i
        i += 1

print(ans)
