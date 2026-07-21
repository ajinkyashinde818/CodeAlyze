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

count = dict(Counter(prime_factorize(N)))

ans = 0
for c in count.values():
    k = 1
    while c >= k:
        ans += 1
        c -= k
        k += 1

print(ans)
