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
counter = 0
for i in set(a):
    cou = a.count(i)
    tmp = 0
    j = 1
    while tmp < cou:
        tmp += j
        j += 1
        if tmp <= cou:
            counter += 1
print(counter)
