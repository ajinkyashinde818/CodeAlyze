import sys
input = sys.stdin.readline
from collections import *

N = int(input())
S = input()[:-1]
cnt = Counter(list(S))
ans = 1
MOD = 10**9+7

for v in cnt.values():
    ans *= v+1
    ans %= MOD

print((ans-1)%MOD)
