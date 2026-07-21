def prime_factorize(n):
    a = []
    while n % 2 == 0:
        a.append(2)
        n //= 2
    f = 3
    while f * f <= n:
        if n % f == 0:
            a.append(f)
            n //= f
        else:
            f += 2
    if n != 1:
        a.append(n)
    return a
from collections import Counter
n = int(input())
ans = 0
list_N = prime_factorize(n)
list_Q = Counter(list_N).values()

for num in list_Q:
    k = 0
    while True:
        k += 1
        if num - k < 0:
            break
        num -= k
        ans += 1

print(ans)
