import sys
input = sys.stdin.readline
sys.setrecursionlimit(200000)
from collections import defaultdict


def read():
    N = int(input().strip())
    return N,


def sieve(n):
    """
    n以下の素数を昇順に列挙する
    """
    is_prime = [True for i in range(n+1)]
    primes = []
    for i in range(2, n+1):
        if is_prime[i]:
            primes.append(i)
            for j in range(i+i, n+1, i):
                is_prime[j] = False
    return primes


def prime_factorization(n, primes):
    """
    nの素因数分解を求める
    """
    prime_factors = defaultdict(int)
    if n < 2:
        return prime_factors
    for p in primes:
        if p * p > n:
            break
        while n % p == 0:
            prime_factors[p] += 1
            n //= p
    if n > 1:
        prime_factors[n] = 1
    return prime_factors


def solve(N, INF = 10**8):
    primes = sieve(10**6+1)
    factors = prime_factorization(N, primes)
    ans = 0
    for c in factors.values():
        m = 0
        for i in range(1, 63):
            if m + i <= c:
                m += i
                ans += 1
            else:
                break
    return ans


if __name__ == '__main__':
    inputs = read()
    outputs = solve(*inputs)
    if outputs is not None:
        print("%s" % str(outputs))
