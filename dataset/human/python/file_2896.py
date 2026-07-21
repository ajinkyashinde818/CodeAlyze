import sys
sys.setrecursionlimit(10000000)
MOD = 10 ** 9 + 7
INF = 10 ** 15

def sieve(n):
    if n == 1:return []
    primes = [1 if i%2 == 1 else 0 for i in range(n + 1)]
    primes[1] = 0
    primes[2] = 1
    for i in range(3,n + 1,2):
        if i * i > n:
            break
        if primes[i]:
            for j in range(i * i,n + 1,i):
                primes[j] = 0
    return [p for p in range(2,n + 1) if primes[p] == 1]

def factorization(n,primes):
    factor = {}
    for p in primes:
        while n%p == 0:
            n //= p
            if p in factor:
                factor[p] += 1
            else:
                factor[p] = 1
    
    if n != 1:
        factor[n] = 1
    
    return factor

def main():
    N = int(input())
    primes = sieve(1000005)
    factor = factorization(N,primes)
    ans = 0
    for k,v in factor.items():
        i = 1
        while v - i >= 0:
            v -= i
            ans += 1
            i += 1
    print(ans)
if __name__ == '__main__':
    main()
