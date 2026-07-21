def factorint(n):
    d = dict()
    for i in range(2, int(n ** 0.5) + 1):
        if n % i == 0:
            c = 0
            while n % i == 0:
                c += 1
                n /= i
            d[i] = c
    if n != 1:
        d[n] = 1
    return d

n = int(input())
c = 0
for i, j in factorint(n).items():
    for k in range(j):
        if n % i ** (k + 1) == 0:
            n = n / i ** (k + 1)
            c += 1
        else:
            break
print(c)
