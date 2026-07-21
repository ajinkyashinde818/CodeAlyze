N = int(input())
def factorization(n): # => {prime:count,...}
    fac = {}
    count = 0
    while n % 2 == 0:
        n //= 2
        count += 1
    if count > 0:
        fac[2] = count
    for i in range(3, int(n ** .5) + 1, 2):
        count = 0
        while n % i == 0:
            n //= i
            count += 1
        if count > 0:
            fac[i] = count
    if n > 1:
        fac[n] = 1
    return fac
ans = 0
for key, cnt in factorization(N).items():
    n = 1
    while cnt >= 0:
        cnt -= n
        n += 1
        ans += 1
    ans -= 1
print(ans)
