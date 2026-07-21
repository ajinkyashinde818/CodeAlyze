from functools import lru_cache
N = int(input())

@lru_cache(maxsize=None)
def isprime(x):
    i = 2
    while i * i <= x:
        if x % i == 0:
            return False
        i += 1
    return True

@lru_cache(maxsize=None)
def ispow(a, b):
    while a % b == 0:
        a //= b
    return a == 1

prime_cache = [2, 3]

def primeiter():
    global prime_cache
    for p in prime_cache:
        yield p
    x = prime_cache[-1] + 1
    while True:
        if isprime(x):
            prime_cache.append(x)
            yield x
        x += 1

done = set()
while N > 1:
    ds = [N]
    d = 2
    while d * d <= N:
        if N % d == 0:
            if not d in done:
                ds.append(d)
            d2 = N // d
            if d2 != d and not d2 in done:
                ds.append(d2)
        d += 1
    ds.sort()
    z = -1
    for d in ds:
        if isprime(d):
            z = d
            break
        for p in primeiter():
            if d < p:
                break
            if ispow(d, p):
                z = d
                break
        if z > 0:
            break
    if z < 0:
        break
    N //= z
    done.add(z)
print(len(done))
