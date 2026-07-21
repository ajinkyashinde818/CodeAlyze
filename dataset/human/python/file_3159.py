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
sum = 0
c = collections.Counter(prime_factorize(n))
index = 1
for i in c.values():
    tmp = i
    # print(str(tmp) + " tmp")
    for j in range(i):
        if j+1 > tmp:
            break
        tmp -= j+1
        sum += 1
print(sum)
# print(c)
