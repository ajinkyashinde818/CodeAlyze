import sys
input = sys.stdin.readline
from collections import defaultdict

def prime(n: int) -> defaultdict:
    f, i = defaultdict(int), 2
    while i * i <= n:
        while n % i == 0: f[i] += 1; n //= i
        i += 1
    if n != 1: f[n] = 1
    return f

def solve(n: int) -> int:
    if n == 1: return 1
    r, l = n, 0
    while (r - l) > 1:
        m = (l + r) // 2
        if m * (m + 1) // 2 <= n: l = m
        else: r = m
    return l

n, res = int(input()), 0
for k, v in prime(n).items(): res += solve(v)
print(res)
