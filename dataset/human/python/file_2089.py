from collections import Counter
mod = 10**9 + 7
n = int(input())
s = [i for i in input()]
cnt = Counter(s)
l = len(cnt)
val = list(cnt.values())
val = [i + 1 for i in val if i != 1]
ans = 2**(l-len(val)) % mod
for vi in val: ans *= vi % mod
print((ans - 1) % mod)
