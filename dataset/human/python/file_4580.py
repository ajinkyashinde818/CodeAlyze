import sys
read = sys.stdin.read
readline = sys.stdin.readline
readlines = sys.stdin.readlines

def prime_factorization(n):
    d = {}
    i = 2
    while i * i <= n:
        if n % i == 0:
            d[i] = 1
            n //= i
            while n % i == 0:
                n //= i
                d[i] += 1
        i += 1
    if n > 1:
        d[n] = 1
    return d

def main():
    N = int(readline())

    d = prime_factorization(N)
    
    ans = 0
    for k, v in d.items():
        e = 0
        for i in range(1, v+1):
            e += i
            if e > v:
                break
            ans += 1

    print(ans)


if __name__ == "__main__":
    main()
