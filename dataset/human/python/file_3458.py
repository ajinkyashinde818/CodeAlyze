N = int(input())
import collections
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
c = collections.Counter(prime_factorize(N))
ans = 0
for i in c.values():
    k = i
    j = 1
    while(k>=j):
        k = k-j
        j += 1
        ans += 1
print(ans)
