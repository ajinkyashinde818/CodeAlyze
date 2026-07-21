from sys import stdin
from sys import setrecursionlimit
import math
from collections import Counter
setrecursionlimit(10 ** 7)

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

li = Counter(prime_factorize(n))
count = li.items()

now = 0
lis = []
for i in range(1000):
    lis.append(now+i)
    now += i

lis = lis[1:]

import bisect
point = 0
for i in count:
    a,b = i
    point += bisect.bisect_right(lis,b)

print(point)
