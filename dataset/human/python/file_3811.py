import copy
from collections import defaultdict

N = int(input())
tmp = copy.copy(N)
d = defaultdict(int)
if N == 1:
    print(0)
    exit()
for i in range(2, int(N ** 0.5) + 3):
    while N % i == 0:
        N //= i
        d[i] += 1
if N > 1:
    d[N] += 1
ans = 0
for i in d.values():
    tmp = 1
    while i - tmp >= 0:
        i -= tmp
        tmp += 1
        ans += 1
print(ans)
