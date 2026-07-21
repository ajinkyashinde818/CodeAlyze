import math
from collections import Counter

N = int(input())

def getPrimeFactors(x):
    anss = []
    while x%2 == 0:
        anss.append(2)
        x //= 2
    for d in range(3, int(x**0.5)+1, 2):
        while x%d == 0:
            anss.append(d)
            x //= d
    if x != 1:
        anss.append(x)
    return anss

PFs = getPrimeFactors(N)
cnt = Counter(PFs)

ans = 0
for _, e in cnt.items():
    base = e * 2
    root = math.floor(math.sqrt(base))
    if root * (root + 1) > base:
        root -= 1
    ans += root
print(ans)
