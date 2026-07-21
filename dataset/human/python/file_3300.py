import collections
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
l  = list(collections.Counter(prime_factorize(n)).values())
count = 0
for i in l:
    x = i
    check = 1
    while True:
        if x >= check:
            x -= check
            count += 1
            check += 1
        else:
            break
print(count)
