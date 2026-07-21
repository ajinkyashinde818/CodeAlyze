from collections import Counter

N = int(input())

sosu = []
while N % 2 == 0:
    sosu.append(2)
    N = int(N/2)

f = 3
while f * f <= N:
    while N % f == 0:
        sosu.append(f)
        N = int(N/f)
    f += 2
if N != 1: sosu.append(N)

count = Counter(sosu)

ans = 0
for k,v in count.items():
    beki = 1
    while beki <= v:
        ans += 1
        v -= beki
        beki += 1
print(ans)
