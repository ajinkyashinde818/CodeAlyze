def factorize(n):#素因数分解
    fct = []  # prime factor
    b, e = 2, 0  # base, exponent
    while b * b <= n:
        while n % b == 0:
            n = n // b
            e = e + 1
        if e > 0:
            fct.append([b, e])
        b, e = b + 1, 0
    if n > 1:
        fct.append([n, 1])
    return fct

n = int(input())

l = factorize(n)

m = len(l)

ans = 0

for i in range(m):
    x = l[i][1]
    for j in range(1, 50):
        if x >= j:
            ans += 1
            x -= j
        else:
            break

print(ans)
