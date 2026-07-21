import sys
stdin = sys.stdin

ni = lambda: int(ns())
na = lambda: list(map(int, stdin.readline().split()))
nn = lambda: list(stdin.readline().split())
ns = lambda: stdin.readline().rstrip()

n = ni()
s = ns()

mod = 10**9+7

from collections import defaultdict

ans = 1
d = defaultdict(int)

for i in range(n):
	d[s[i]] += 1

for v in d.values():
	ans *= (v+1)
	ans = ans%mod

print(ans-1)
