from collections import defaultdict
N = int(input())
S = input()
mod = 10 ** 9 + 7
d = defaultdict(int)
char = [chr(ord("a") + i) for i in range(26)]
ans = 1
for s in S:
    d[s] += 1
for v in d.values():
    ans *= v + 1
    ans %= mod
print(ans - 1)
