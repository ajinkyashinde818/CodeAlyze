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

PrimeFactors = collections.Counter(prime_factorize(N))
countPrime = PrimeFactors.values()
cnt = 0
for i in countPrime:
    counter = 0
    for j in range(1,20):
        i = i - j
        if i >= 0:
            cnt += 1
        else:
            break
print(cnt)
