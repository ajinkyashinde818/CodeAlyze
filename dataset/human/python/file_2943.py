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
N=int(input())
D = collections.Counter(prime_factorize(N))
A=0
for d in D:
    e=D[d]
    for i in range(40):
        if (i+1)*(i+2)>2*e:
            A=A+i
            break
print(A)
