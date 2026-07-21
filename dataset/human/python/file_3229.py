n = int(input())
N = n
arr = [n]
while n % 2 == 0:
    arr.append(2)
    n //= 2
f = 3
while f * f <= n:
    if n % f == 0:
        arr.append(f)
        n //= f
    else:
        f += 2
if n != 1:
    arr.append(n)


arr.sort()

import collections
c = collections.Counter(arr)
k = list(c.keys())
v = list(c.values())

x = []
for i in range(len(k)):
    for p in range(1,v[i]+1):
        x.append(k[i]**p)

x.sort()

ans = 0
n = N
while n != 1 and len(x) != 0:
    if n % x[0] == 0:
        n //= x[0]
        x.pop(0)
        ans += 1
    else:
        x.pop(0)
print(ans)
