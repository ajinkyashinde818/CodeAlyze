from collections import Counter


n = int(input())

if n == 1:
    print(0)
    exit()


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


ans = 0
for v in Counter(prime_factorize(n)).values():
    i = 1
    while v >= i:
        v -= i
        ans += 1
        i += 1

print(ans)
