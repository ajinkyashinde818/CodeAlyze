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
ans = 0
primes = prime_factorize(N)
pc = Counter(primes)
for v in pc.values():
    now = 1
    while now*(now+1)//2 <= v:
        now += 1
    ans += now-1
print(ans)
