from collections import defaultdict

def prime_factors(n):
    d = defaultdict(int)
    while n%2 == 0:
        d[2] += 1
        n //= 2
    i = 3
    while i*i <= n:
        while n%i == 0:
            d[i] += 1
            n //= i
        i += 2
    if n > 2:
        d[n] += 1
    return d

N = int(input())
ans = 0
done = set()
# print(prime_factors(N))
for k,v in prime_factors(N).items():
    p = 0
    while v > 0:
        p += 1
        v -= 1
        if not pow(k, p) in done:
            ans += 1
            done.add(pow(k, p))
            p = 0
print(ans)
