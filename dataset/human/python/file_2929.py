import collections

N = int(input())


def prime_factorization(n):
    """Algorithm: trial division"""
    divs = []
    div = 2
    while n % div == 0:
        divs.append(div)
        n //= div
    div = 3
    while div ** 2 <= n:
        if n % div == 0:
            divs.append(div)
            n //= div
        else:
            div += 2
    if n != 1:
        divs.append(n)
    return divs


div_count_map = collections.Counter(prime_factorization(N))
ans = 0
for div, cnt in div_count_map.items():
    e = 1
    while e <= cnt:
        ans += 1
        cnt -= e
        e += 1
print(ans)
