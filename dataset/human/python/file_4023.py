n = int(input())
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
p = prime_factorize(n)

import collections
cnt = collections.Counter(p)

ans = 0
for pi, ci in cnt.items():
    num = 1
    for i in range(1, 10000):
        if (i * (i+1))//2 <= ci:
            num = i
        if (i * (i+1))//2 > ci:
            break
    ans += num

print(ans)
