import sys
from collections import Counter
from typing import Iterator

def traial_division(n: int) -> Iterator[int]:
    while not n % 2:
        yield 2
        n //= 2
    v = 3
    while v * v <= n:
        if not n % v:
            yield v
            n //= v
        else:
            v += 2
    if n != 1:
        yield n

n = int(sys.stdin.read())
c = Counter(traial_division(n))
# print(c)
ans = 0
for i, k in c.items():
    j = 1
    while k >= j:
        k -= j
        ans += 1
        j += 1
print(ans)
