import sys
input = sys.stdin.readline

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

a = prime_factorize(n)
from collections import Counter
c = Counter(a)
ans = 0
for i in c.keys():
    cnt = 1
    while c[i] >= cnt:
        ans += 1
        c[i] -= cnt
        cnt += 1
print(ans)
