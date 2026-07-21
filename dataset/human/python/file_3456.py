from collections import Counter

def prime_factorize(n):
    a = []
    while n % 2 == 0:
        a.append(2)
        n //= 2
    f = 3
    while f * f <= n:
        while n % f == 0:
            a.append(f)
            n //= f
        f += 2
    if n != 1:
        a.append(n)
    return a

x = int(input())
y = Counter(prime_factorize(x))

num = 0
for v in y.values():
    now_v = v
    i = 1
    while True:
        if now_v < i:
            break
        now_v -= i
        num += 1
        i += 1

print(num)
