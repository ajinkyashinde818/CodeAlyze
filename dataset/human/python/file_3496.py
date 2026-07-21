import numpy as np

MAX = 10**6
is_prime = [True] * MAX
is_prime[0] = False
is_prime[1] = False
primes = []
for i in range(MAX):
    if is_prime[i]:
        primes.append(i)
        for j in range(2*i, MAX, i):
            is_prime[j] = False

a = np.cumsum([i+1 for i in range(100)])

def decomp(n):
    res = {}
    for p in primes:
        while n % p == 0:
            if not p in res:
                res[p] = 0
            res[p] += 1
            n //= p
    if n > 1:
        res[n] = 1
    return res

def solve(n):
    ans = 0
    for num in decomp(n).values():
        k = 0
        while a[k] <= num:
            k += 1
        ans += k
    return ans

n = int(input())
print(solve(n))
