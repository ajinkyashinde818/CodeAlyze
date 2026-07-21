from collections import defaultdict
n = int(input())
d = defaultdict(int)
k = 2
while n > 1 and k * k <= n:
    if n % k == 0:
        d[k] += 1
        n //= k
    else:
        k += 1
if n > 1:
    d[n] += 1
ans = 0
for k,v in d.items():
    a = 1
    while v >= a:
        v -= a
        a += 1
        ans += 1
print(ans)
