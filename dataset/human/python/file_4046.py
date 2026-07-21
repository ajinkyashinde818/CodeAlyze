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

def sankaku(n):
    i = 1

    while not (n < i*(i+1) / 2):
        i += 1
    
    return i - 1

N = int(input())

delist = prime_factorize(N)

counter = collections.Counter(delist)

count = 0

for key, value in counter.items():
    count = count + sankaku(value)

print(count)
