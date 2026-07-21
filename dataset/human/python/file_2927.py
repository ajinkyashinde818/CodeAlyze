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

c = collections.Counter(prime_factorize(N))

a = [0 for _ in range(40)]
start = 0
for i in range(8):
    a[start:start+(i+2)] = [i+1 for _ in range(i+2)]
    start = start + (i+2)

ans = 0
for i in list(c.values()):
    ans += a[i-1]

print(ans)
