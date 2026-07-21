n = int(input())

if n == 1:
    print(0)
    exit()

def factrize(n):
    b = 2
    fct = []
    while b * b <= n:
        while n % b == 0:
            n //= b
            fct.append(b)
        b = b + 1
    if n > 1:
        fct.append(n)
    return fct

l = factrize(n)
from collections import Counter
dic = Counter(l)

ans = 0
for i in dic.values():
    j = 0
    k = 1
    while i >= k:
        i -= k
        j += 1
        k += 1
    ans += j
print(ans)
