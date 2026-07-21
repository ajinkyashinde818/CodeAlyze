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
c = Counter(prime_factorize(N))

ans = 0
for v in c.values():
    n = 1
    while n <= v:
        v -= n
        ans += 1
        n+=1
print(ans)
