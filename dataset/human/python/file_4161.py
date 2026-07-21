N = int(input())
import collections
import math
cnt = 0
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
v = c.values()
for i in v:
	cnt += math.floor((math.sqrt(8*i+1)-1)/2)
print(cnt)
