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

tri = [1]
for i in range(2,30):
    tri.append(tri[-1]+i)
n = int(input())
a = factorize(n)
ans = 0
for num,v in a:
    for k,i in enumerate(tri):
        if i > v:
            ans += k
            break
print(ans)
