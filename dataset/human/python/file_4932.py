MOD = 10 ** 9 + 7

N = int(input())
xs = list(map(int, input().split()))

from itertools import accumulate

def mulmod(a, b):
    return a * b % MOD
    
from_left = list(accumulate(range(N-1, 1, -1), mulmod))[::-1] + [1]
from_right = [1] + list(accumulate(range(1, N-1), mulmod))
count = list(accumulate([mulmod(l, r) for l, r in zip(from_left, from_right)]))

ans = 0
for i in range(N-1):
    ans += (xs[i+1] - xs[i]) * count[i]
    ans %= MOD

print(ans)
