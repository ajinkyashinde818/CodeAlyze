from collections import defaultdict
n = int(input())
s = input()
MOD = 10**9 + 7

dd = defaultdict(int)
for c in s:
    dd[c] += 1
ans = 0
for c in s:
    dd[c] -= 1
    tmp = 1
    for k, v in dd.items():
        if k == c:
            continue
        else:
            tmp *= v + 1
    ans = (ans + tmp) % MOD

print(ans)
