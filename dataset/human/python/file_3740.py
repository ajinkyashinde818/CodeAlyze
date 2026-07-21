import collections

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

if __name__ == "__main__":
    n = int(input())
    lst = collections.Counter(prime_factorize(n))

    #primes = lst.keys()
    counts = lst.values()

    ans = 0
    for c in counts:
        num = c
        cnt = 1
        while True:
            num -= cnt
            if num < 0:
                break
            ans += 1
            cnt += 1
    
    print(ans)
