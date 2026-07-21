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
l = prime_factorize(n)
set = list(set(l))
result = 0

for i in range(len(set)):
    tmp = l.count(set[i])
    for j in range(l.count(l[i])):
        if j+1 <= tmp:
            result += 1
            tmp -= j+1
        else:
            break

print(result)
