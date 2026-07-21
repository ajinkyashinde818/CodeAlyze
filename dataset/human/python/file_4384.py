import numpy as np
from math import sqrt

def sieve(n):
    S = [True] * (n+1)
    S[0] = S[1] = False
    i = 2
    while i * i <= n:
        if S[i]:
            k = i * i
            while k <= n:
                S[k] = False
                k += i
        i += 1
    return S

  
def arrayF(n): 
    F=[0]*(n+1) 
    i=2 
    while i*i<=n:
        if F[i] == 0: 
            k=i*i
            while k <= n:
                if F[k] == 0:
                    F[k] = i
                k += i
        i += 1 
    return F


def factorization(x, F): 
    primeFactors = [] 
    while (F[x] > 0):
        primeFactors.append(F[x])
        x //= F[x] 
    primeFactors.append(x) 
    return primeFactors


n = int(input())
if n == 1:
    print(0)
    exit(0)

rt = int(sqrt(n)+1)
S = sieve(rt)
primes = np.arange(rt+1)[S]

for i in primes:
    if n % i == 0:
        break
else:
    print(1)  # n is prime
    exit(0)

m = n
facts = {}
for i in primes:
    if m % i == 0:
        facts[i] = 0
        while m % i == 0:
            m //= i
            facts[i] += 1
if m != 1:
    facts[m] = 1

for k in facts:
    v = facts[k]
    if v < 3:
        facts[k] = 1
    elif v < 6:
        facts[k] = 2
    elif v < 10:
        facts[k] = 3
    elif v < 15:
        facts[k] = 4
    elif v < 21:
        facts[k] = 5
    elif v < 28:
        facts[k] = 6
    elif v < 36:
        facts[k] = 7
    elif v < 45:
        facts[k] = 8
    elif v < 55:
        facts[k] = 9
    elif v < 66:
        facts[k] = 10
print(sum(facts.values()))
