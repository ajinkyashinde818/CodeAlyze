from collections import defaultdict
import sys
N = int(input())

if N == 1:
    print(0)
    sys.exit(0)


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


T = prime_factorize(N)


q = defaultdict(int)
p = set(T)

for t in T:
    q[t] += 1

ans = 0

for pp in list(p):
    count = 0
    tmp = 0
    while True:
        tmp += 1
        count += tmp + 1
        if count >= q[pp]:
            break
    ans += tmp

print(ans)
