from collections import Counter

def factorize(n):
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


N = int(input())
arr = dict(Counter(factorize(N)))
ans = 0

for v, c in arr.items():
    z = 0
    for i in range(1, c+1):
        z += i
        if c - z < 0:
            break
        ans += 1
print(ans)
