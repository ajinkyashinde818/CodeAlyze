from functools import reduce

N = int(input())
MOD = 10**9 + 7

def mul(a, b):
    return ((a % MOD)*(b % MOD)) % MOD

cnt = {}
for b in input():
    cnt[b] = cnt[b] + 1 if b in cnt else 2

print(reduce(mul, cnt.values()) - 1)
