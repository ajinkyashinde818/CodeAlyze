from collections import Counter

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

n = int(input())
a = prime_factorize(n)
c = Counter(a)
ans = 0
for k,v in c.items():
    ans += 1
    now = 1
    v -= now
    while now < v:
        ans += 1
        now += 1
        v -= now
print(ans)
