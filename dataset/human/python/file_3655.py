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

c = collections.Counter(prime_factorize(N))
sum = 0

for i in c.keys():
    a = c[i]
    for n in range(c[i]):
        if a<n+1:
            break
        else:
            a-=n+1
            sum+=1

print(sum)
