N = int(input())

def factorize(n):
    fct = []  # prime factor
    b, e = 2, 0  # base, exponent
    while b * b <= n:
        while n % b == 0:
            n = n // b
            e = e + 1
        if e > 0:
            fct.append((b, e))
        b, e = b + 1, 0
    if n > 1:
        fct.append((n, 1))
    return fct

data = factorize(N)

ans = 0
j = 1
for i in range(len(data)):
    k = data[i][1]
    while k - j >= 0:
        k -= j
        ans += 1
        j += 1
    j = 1

print(ans)
