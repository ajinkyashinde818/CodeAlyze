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

def cnt(x):
    ans = 0
    i = 1
    while True:
        ans += i
        if ans > x:
            return i-1
        i += 1
        
n = int(input())
ans = 0

a = Counter(prime_factorize(n))
for i in a.values():
    ans += cnt(i)

print(ans)
