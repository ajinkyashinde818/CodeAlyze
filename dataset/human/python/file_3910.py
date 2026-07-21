import sys

n = int(sys.stdin.readline())

def isPrime(n):
    if n < 2:
        return False
    for i in range(2,int(n**0.5)+1):
        if n%i==0:
            return False
    return True

def divisors(n):
    lower_divisors , upper_divisors = [], []
    i = 1
    while i*i <= n:
        if n % i == 0:
            lower_divisors.append(i)
            if i != n // i:
                upper_divisors.append(n//i)
        i += 1
    return lower_divisors + upper_divisors[::-1]

def calc(n):
    used = set()
    a = 0
    c = True
    c1 = []
    ds = divisors(n)
    m = max(ds)
    for d in ds:
        if not isPrime(d):
            continue
        v = d
        i = 1
        while v <= m:
            c1.append(v)
            i += 1
            v = d ** i
    c1.sort()
    while c:
        c = False
        for d in c1:
            if d in used:
                continue
            if n % d != 0:
                continue
            #print(n, d)
            n //= d
            a += 1
            c = True
            used.add(d)
            break
    return a

print(calc(n))
