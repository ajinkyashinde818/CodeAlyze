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

primes = collections.Counter(prime_factorize(N))

answer = 0

for key in primes:
    number = primes[key]
    minus_number = 1
    while True:
        number -= minus_number
        if number < 0:
            break
        minus_number += 1
    answer += (minus_number - 1)

print(answer)
