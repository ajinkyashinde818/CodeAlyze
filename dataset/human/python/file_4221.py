import collections
import bisect
n = int(input())

primes = []
a = 2
while n > a*a:
    while n % a == 0:
        primes.append(a)
        n //= a
    a += 1
if n != 1:
    primes.append(n)

ctr = collections.Counter(primes)
ans = 0
for k,v in ctr.items():
    for i in range(1,100):
        if v >= i*(i+1)//2:
            ans += 1
print(ans)
