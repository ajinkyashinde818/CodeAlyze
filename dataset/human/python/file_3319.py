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

a = prime_factorize(N)
c = collections.Counter(a)

ind = []
ans = 0
for x in range(1,10):
    ans += x
    ind.append(ans)

cnt = 0
for y in c.values():
    for j,x in enumerate(ind):
        if y < x:
            cnt += j
            break

print(cnt)
