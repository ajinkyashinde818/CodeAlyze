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


n = int(input())
c = collections.Counter(prime_factorize(n))
l = c.values()
ans=0
for i in list(l):
    temp = i
    j=1
    while temp > 0:
        if temp < j:
            break
        temp -= j
        j += 1
        ans += 1
print(ans)
