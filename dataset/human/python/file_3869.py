def prime_factor(n):
    factors = {}
    if n % 2 == 0:
        cnt = 0
        while n % 2 == 0:
            cnt += 1
            n //= 2
        factors[2] = cnt
    i = 3
    while i * i <= n:
        if n % i == 0:
            cnt = 0
            while n % i == 0:
                cnt += 1
                n //= i
            factors[i] = cnt
        i += 2
    if n != 1:
        factors[n] = 1
    return factors

N = int(input())
ans = 0
prime_factors = prime_factor(N)
for k, v in prime_factors.items():
    i = 1
    while v >= i:
        ans += 1
        v -= i
        i += 1
print(ans)
