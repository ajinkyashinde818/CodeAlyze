from collections import Counter
N = int(input())
S = input()
ans = 0
mod = 10 ** 9 + 7
c = Counter(S)
for k in S:
    n = 1
    for i in range(ord("a"), ord("z") + 1):
        i = chr(i)
        if i in c and i != k:
            n *= c[i] + 1
            n %= mod
    ans = (ans + n) % mod
    c[k] -= 1
print(ans)
