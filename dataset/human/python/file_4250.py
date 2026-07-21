from collections import defaultdict


def prime_factor(n):
    d = defaultdict(int)
    for i in range(2, n + 1):
        if i * i > n:
            break

        while n % i == 0:
            d[i] += 1
            n //= i

    if n != 1:
        d[n] += 1

    return d


N = int(input())
d = prime_factor(N)
ans = 0
for v in d.values():
    i = 1
    cur = 1
    cnt = 0
    while cur <= v:
        cnt += 1
        i += 1
        cur += i
    ans += cnt

print(ans)
