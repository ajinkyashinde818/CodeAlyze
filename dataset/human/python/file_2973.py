import collections
N = int(input())

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

c = collections.Counter(prime_factorize(N))
answer = 0

for i in list(c.keys()):
    n = 1
    a = c[i]
    while a > n*(n+1)/2:
        n += 1
    if a == n*(n+1)/2:
        answer += n
    else:
        answer += n-1

print(answer)
