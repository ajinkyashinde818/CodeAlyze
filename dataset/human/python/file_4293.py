import sys
import copy
from collections import Counter
stdin = sys.stdin
 
ni = lambda: int(ns())
na = lambda: list(map(float, stdin.readline().split()))
ns = lambda: stdin.readline().rstrip()  # ignore trailing spaces
n = ni()

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

def count(p):
    cnt = 0
    now = 1
    while p>0:
        if p < now:
            break
        p -= now
        cnt += 1
        now += 1
    return cnt

c = Counter(prime_factorize(n))
res = 0
for v in c.values():
    res += count(v)

print(res)
