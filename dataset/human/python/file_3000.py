n = int(input())

def prime_factor(n):
    factor = []
    for i in range(2, int(n ** 0.5) + 1):
        while (n % i == 0):
            factor.append(i)
            n //= i
    if n != 1:
        factor.append(n)
    return list(set(factor))

factor = prime_factor(n)

cnt = 0
for p in factor:
    if n % p == 0:
        e = 1
        while n % pow(p, e) == 0:
            cnt += 1
            n //= pow(p, e)
            e += 1

print(cnt)
