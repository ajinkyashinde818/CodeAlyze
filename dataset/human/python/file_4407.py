import math
def main():

    N = int(input())
    primes = []
    def isprime(n):
        if n == 1: return False
        for i in range(2, int(math.sqrt(n))+1):
            if n % i == 0:
                return False
        return True

    primes = set()
    for i in range(1, int(math.sqrt(N))+1):
        if N % i == 0:
            if isprime(i):
                primes.add(i)
            if isprime(N//i):
                primes.add(N//i)
    if isprime(N):
        primes.add(N)

    ans = 0
    for p in primes:
        q = p
        while N % q == 0:
            ans += 1
            N //= q
            q *= p
        if N == 1:
            break
    return ans


if __name__ == '__main__':
    print(main())
