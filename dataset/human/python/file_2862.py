from bisect import bisect
from itertools import accumulate as acc
N = int(input())

d = dict()
for i in range(2, int(N**(1/2))+2):
    if N%i == 0:
        d[i] = 0
    while N%i == 0:
        d[i] += 1
        N //= i
if N != 1:
    d[N] = 1

a = list(acc(range(1, 100)))

r = 0
for v in d.values():
    r += bisect(a, v)

print(r)
