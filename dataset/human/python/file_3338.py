from math import sqrt
from collections import defaultdict

N = int(input())

f = defaultdict(int)
for p in [2] + list(range(3, int(sqrt(N)) + 1, 2)):
    while N % p == 0:
        N //= p
        f[p] += 1
    if N == 1:
        break
if N != 1:
    f[N] += 1

ans = 0
for e in f.values():
    ans += int((sqrt(1 + 8 * e) - 1) / 2)
print(ans)
