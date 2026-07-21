import math
import collections
n = int(input())

ans = 0

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

if a == []:
    print(0)
else:
    c = collections.Counter(a)
    for i in c.values():
        m = 1
        while 2*(i+1)>(m+1)*(m+2):
            m += 1
        ans += m
    print(ans)
