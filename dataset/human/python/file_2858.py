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
p = prime_factorize(n)
c = Counter(p)
ans = 0
for i in c.keys():
    ans += 1
    x = c[i]
    y = 3
    i = 3
    if x > 2:
        while True:
            if x < y:
                break
            else:
                ans += 1
                y += i
                i += 1
print(ans)
