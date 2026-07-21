def is_prime(N):
    i = 2
    table = []
    while i*i <= N:
        while N%i == 0:
            N //= i
            table.append(i)
        i += 1
    if N > 1:
        table.append(N)
    return table

from itertools import groupby
N = int(input())
P = is_prime(N)
ans = 0
for v, g in groupby(P):
    n = len(list(g))
    for i in range(1, 10**5):
        n -= i
        if n >= 0:
            ans += 1
        else:
            break
print(ans)
