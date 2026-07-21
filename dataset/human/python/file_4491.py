n = int(input())


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
a = prime_factorize(n)
b = list(set(a))
total = 0
for j in range(len(b)):
    c  = len([i for i, x in enumerate(a) if x == list(set(a))[j]])
    y = 1
    while c>0:
        c -= y
        y += 1
        if c>=0:
            total +=1
print(total)
