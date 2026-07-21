import numpy as np

def prime_factorize(n):
    a = []
    while n % 2 == 0:
        a.append(2)
        n //= 2
    f = 3
    while f * f <= n:
        if n % f == 0:
            a.append(f)
            n //= f
        else:
            f += 2
    if n != 1:
        a.append(n)
    return a


def main():
    N = int(input())
    
    primes = prime_factorize(N)
    u, counts = np.unique(primes, return_counts=True)
    
    ans = 0
    for c in counts:
        i = 1
        while c - i >= 0:
            c -= i
            i += 1
            ans += 1
    print(ans)


if __name__ == "__main__":
    main()
