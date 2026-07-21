import numpy as np

def seachPrimeNum(MAX):
    prime = np.zeros(MAX, np.bool_)
    prime[2] = 1
    prime[3::2] = 1
    for p in range(3, MAX, 2):
        if p * p >= MAX:
            break
        if prime[p]:
            prime[p * p::p + p] = 0
    
    return prime.nonzero()[0]

N = int(input())
n = N
s = 0

prime = np.array(seachPrimeNum(int(np.sqrt(10**12))))
prime = prime[N % prime == 0]

for p in prime:
    e = 1
    while n % p == 0:
        if n % p ** e == 0:
            n = n / p ** e
            e = e + 1
            s += 1
        else:
            n = n / p

if n != 1:
    s += 1

print(s)
