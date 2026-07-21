n = int(input())
def prime_factors(n):
    i = 2
    factors = []
    while i * i <= n:
        if n % i:
            i += 1
        else:
            n //= i
            factors.append(i)
    if n > 1:
        factors.append(n)
    return factors

f = list(set(prime_factors(n)))
ans = 0
for i in f:
    e = 1
    while n % i**e == 0:
        n = n//(i**e)
        ans += 1
        e+=1

print(ans)
