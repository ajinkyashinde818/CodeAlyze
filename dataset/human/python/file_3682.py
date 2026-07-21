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

c1 = collections.Counter(prime_factorize(N))
ans = 0
c = list(c1.values())
# print(c)

for i in c:
    k = 1
    while True:
        i =i - k
        if i >=0:
            ans += 1
            k += 1
        else:
            break
print(ans)
