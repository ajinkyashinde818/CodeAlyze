from string import ascii_lowercase
from collections import defaultdict


N = int(input())
S = input().strip()
MOD = 10 ** 9 + 7


c = defaultdict(int)
for i in range(N):
    c[S[i]] += 1

ans = 1
for x in ascii_lowercase:
    ans *= c[x] + 1
    ans %= MOD
ans -= 1
ans %= MOD
print(ans)
