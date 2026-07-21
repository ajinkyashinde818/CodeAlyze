from collections import defaultdict
import math

N = int(input())

d = defaultdict(int)
for i in range(2, int(math.sqrt(N)) + 1):
    while N % i == 0:
        d[i] += 1
        N //= i
if N > 1:
    d[N] = 1

ans = 0
for v in d.values():
    k = 1
    while k <= v:
        ans += 1
        v -= k
        k += 1
print(ans)
