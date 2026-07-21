n = int(input())

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

f = factorize(n)
ans = 0
for i,j in f:
    ans += int((-1+pow(1+8*j,0.5))/2)
print(ans)
