import collections

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

def cnt(a,b):
    if a >= b:
        return cnt(a-b,b+1)
    else:
        return b - 1
    

c = collections.Counter(prime_factorize(n))
cn = 0
for i in c.values():
    cn += cnt(i,1)

print(cn)

# print(list(c.values()))
