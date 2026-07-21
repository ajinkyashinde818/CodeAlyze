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

def getScore(n):
    c = 0
    for i in range(1, 100):
        c += i
        if n < c:
            return i-1
    return 0


from collections import defaultdict
factors = defaultdict(int)
res = prime_factorize(N)
for n in res:
    factors[n] += 1


ans = 0
for k in factors.keys():
    ans += getScore(factors[k])

print(ans)
