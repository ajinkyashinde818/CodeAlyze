import sys
import numpy as np

read = sys.stdin.buffer.read
readline = sys.stdin.buffer.readline
readlines = sys.stdin.buffer.readlines

N = int(read())

U = 10**6
is_prime = np.zeros(U, np.bool_)
is_prime[2] = 1
is_prime[3::2] = 1
for p in range(3, U, 2):
    if p * p >= U:
        break
    if is_prime[p]:
        is_prime[p * p::p + p] = 0

primes = is_prime.nonzero()[0]

def factor(N):
    div = primes[N % primes == 0]
    for p in div:
        e = 0
        while N % p == 0:
            e += 1
            N //= p
        yield (p, e)
    if N != 1:
        yield (N, 1)

A = np.zeros(100, np.int32)
for i in range(14):
    k = i * (i + 1) // 2
    A[k] = i
np.maximum.accumulate(A, out=A)

x = 0
for p, e in factor(N):
    x += A[e]
print(x)
