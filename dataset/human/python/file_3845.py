import collections
import bisect

def prim(n):
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

n=int(input())
p=prim(n)
c = collections.Counter(p)
d=c.values()
m=0

l=[1]
for i in range(2,100):
        l.append(i+l[-1])
for i in d:
        m+=bisect.bisect_right(l,i)
print(m)
