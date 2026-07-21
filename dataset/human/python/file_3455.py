N = int(input())
a = []
def prime_factorize(n,a):
    while n % 2 == 0:
        a.append(2)
        n //= 2
    f = 3
    while f * f <= n:
        if n % f == 0:
            a.append(f)
            n //= f
        else:
            f += 2
    if n != 1:
        a.append(n)
    return a

prime_factorize(N, a)
ans = 0
if len(a) > 1:
    before = a[0]
    kosuu = 1
    for i in range(1, len(a)):
        tmp = a[i]
        if tmp == before:
            kosuu += 1
        else:
            ini = 1
            while kosuu - ini >= 0:
                kosuu = kosuu - ini
                ini += 1
                ans += 1
            before = tmp
            kosuu = 1
        ini = 1
    while kosuu - ini >= 0:
        kosuu = kosuu - ini
        ini += 1
        ans += 1
if len(a) == 1:
    ans = 1
print(ans)
