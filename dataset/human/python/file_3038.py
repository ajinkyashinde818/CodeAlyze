"""
これは、Nを構成する素因数の種類の数はいくつか？という問題と等価では？
いや、ちょっと違うな。
2の素因数が3つあれば、2,4で割れる。
Nを素因数分解して、各素因数の数をカウント。
"""
from collections import Counter
N = int(input())
primes = []
d = 2
while d**2 <= N:
    if N%d == 0:
        primes.append(d)
        N //= d
    else:
        d += 1
if N != 1:
    primes.append(N)
count = Counter(primes)


ans = 0
for v in count.values():
    f = 1
    while v >= f:
        ans += 1
        v -= f
        f += 1

print(ans)
