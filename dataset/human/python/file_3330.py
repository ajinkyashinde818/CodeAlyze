N = int(input())


def factors(n):
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


p = list(set(factors(N)))
ans = 0
e = 0
i = 0
for i in range(len(p)):
    e = 1
    while 1 < N:
        z = p[i] ** e
        if N % z == 0:
            N //= z
            ans += 1
        else:
            break
        e += 1
print(ans)
