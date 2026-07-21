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

from collections import Counter

N = int(open(0).read())
l = prime_factorize(N)
c = Counter(l)
ans = 0
cl = [x for x in c.values()]
for i in range(1,41):
    for j in range(len(cl)):
        if cl[j] >= i:
            ans += 1
            cl[j] -= i
print(ans)
