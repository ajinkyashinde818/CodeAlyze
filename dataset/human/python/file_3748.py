import math
import sys
import collections

n = int(input())

if n == 1:
    print(0)
    sys.exit()
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
c = collections.Counter(a)
list = c.values()
ANS = 0
for l in list:
    i = 1
    cnt = 1
    while l >= cnt:
        ANS += 1
        i += 1
        cnt += i
print(ANS)
