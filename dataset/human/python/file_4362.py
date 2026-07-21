import math
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


N = int(input())

counter = collections.Counter(prime_factorize(N))
#print(counter)

ans = 0
for key in counter.keys():
    num = counter[key]
    i = 1
    while num >= i:
        num -= i
        ans += 1
        i += 1

print(ans)
