from collections import Counter
from collections import defaultdict


def trivial_division(n):
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


# n乗のときの最大試行回数
dd = defaultdict(int)
total = 0
for i in range(1, 100):
    for j in range(total, total+i):
        dd[j] = i-1
    total += i

# 素因数分解後、各頻度を抽出
N = int(input())
li = trivial_division(N)
cnt = Counter(li)

ans = 0
for v in cnt.values():
    ans += dd[v]
print(ans)
