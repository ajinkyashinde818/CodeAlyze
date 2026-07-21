import sys
N = int(sys.stdin.readline().rstrip())

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

primes = prime_factorize(N)

from collections import Counter

cnts = Counter(primes)
ans = 0
for p, cnt in cnts.items():
    tmp = 1
    while cnt - tmp >= 0:
        cnt -= tmp
        tmp += 1
        ans += 1
print(ans)
