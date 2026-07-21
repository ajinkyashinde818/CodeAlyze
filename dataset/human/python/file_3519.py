import collections
n = int(input())
result = 0
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

c = collections.Counter(prime_factorize(n))
for i in c.values():
    temp = 0
    for j in range(i+1):
        if (1+j/2)*(j+1) > i:
            result += j
            break
        else:
            continue
print(result)
