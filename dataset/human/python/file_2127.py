from sys import stdin
from collections import Counter
N = int(stdin.readline().rstrip())
S = Counter(stdin.readline().rstrip()).most_common()
MOD = 10**9+7
ans = 1
for k, v in S:
    ans *= (v+1)
    ans %= MOD
print(ans-1)
