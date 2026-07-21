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

N = int(input())
fact = prime_factorize(N)

b = []
c = fact.copy()
q = 1
for p in fact:
    if p not in b:
        while c.count(p) >= q:
            for i in range (q):
                c.remove(p)
                #print(c)
            b.append(p ** q)
            #print(b)
            q += 1
    q = 1
    #print(p)
    #print(fact)

print(len(b))
