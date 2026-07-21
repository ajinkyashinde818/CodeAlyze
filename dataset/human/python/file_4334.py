from collections import Counter
N = int(input())

def prime_factorization(n):
    table = []
    for x in range(2, int(n ** 0.5) + 1):
        while n % x == 0:
            table.append(x)
            n //= x
    if n > 1:
        table.append(n)
    return table


T = prime_factorization(N)
C = Counter(T)

ans = 0
for v in C.values():
    nx = 1
    while v >= nx:
        v -= nx
        ans += 1
        nx += 1

print(ans)
