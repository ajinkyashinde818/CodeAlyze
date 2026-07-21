from collections import Counter

N = int(input())

def prime_factorize(n):
    a = []
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

a = prime_factorize(N)
num = list(Counter(a).values())

ans = 0
for i in num:
    j = 1
    while i - j >= 0:
        ans += 1
        i -= j
        j += 1

print(ans)
