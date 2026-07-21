import sys
input = lambda: sys.stdin.readline().rstrip()

def factorize(n):
    fct = []  # prime factor
    b, e = 2, 0  # base, exponent
    while b * b <= n:
        while n % b == 0:
            n = n // b
            e = e + 1
        if e > 0:
            fct.append((b, e))
        b, e = b + 1, 0
    if n > 1:
        fct.append((n, 1))
    return fct

def main():
    n = int(input())
    primes = factorize(n)
    ans = 0
    for prime in primes:
        i = 1
        cnt = 0
        while True:
            if cnt + i > prime[1]:
                break
            else:
                cnt += i
                i += 1
        ans += (i - 1)
    print(ans)
    
if __name__ == '__main__':
    main()
