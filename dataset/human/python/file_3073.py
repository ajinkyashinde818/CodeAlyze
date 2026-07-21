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
a = prime_factorize(n)
c = collections.Counter(a)
num = 0
for v in c.values():
    for i in range(1,n):
        v -= i
        if v >=0:
            num +=1
        else:break

print(num)
