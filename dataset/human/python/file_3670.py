from itertools import accumulate
import bisect

N = int(input())
l = list(accumulate(range(1, 20)))
ans = 0

def prime_decomposition(n):
    i = 2
    table = []
    while i * i <= n:
        while n % i == 0:
            n //= i
            table.append(i)
        i += 1
    if n > 1:
        table.append(n)
    return table

p = prime_decomposition(N)
dic = {}
for v in p:
    if not v in dic:
        dic[v] = 0
    dic[v] += 1

for v in dic.values():
    i = bisect.bisect_right(l, v)
    ans += i

print(ans)
