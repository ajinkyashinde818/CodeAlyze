from collections import defaultdict


def factorize(n):
    facts = defaultdict(int)
    while n % 2 == 0:
        n //= 2
        facts[2] += 1
    m = 3
    while m * m <= n:
        while n % m == 0:
            facts[m] += 1
            n //= m
        m += 2
    if 1 < n:
        facts[n] += 1
    return facts


N = int(input())

ans = 0
facts = factorize(N)
for num in facts.values():
    for i in range(1, num + 1):
        if i <= num:
            num -= i
            ans += 1
        else:
            break
print(ans)
