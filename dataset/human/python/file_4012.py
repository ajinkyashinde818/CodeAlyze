import random
import collections

N = int(input())
def prime_factorize(n):
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

l = prime_factorize(N)
c = collections.Counter(l)

kazu_l = [1, 1]
t = 1
for i in range(100):
    for j in range(t+2):
        kazu_l.append(t+1)
    t += 1

v = list(c.values())
ans = 0

for i in range(len(v)):
    ans += kazu_l[v[i]-1]

print(ans)
