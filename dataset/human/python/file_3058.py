import collections

N = int(input())

def prime_factorize(n):
    a = []

    for f in range(2, int(n**0.5) + 1):
        while n % f == 0:
            a.append(f)
            n /= f
    if n != 1:
        a.append(n)
    return a

if N == 1:
    print(0)
else:
    c = collections.Counter(prime_factorize(N))
    ans = 0
    for p, max_e in c.items():
        e = 1
        while max_e > 0:
            N /= p ** e

            ans += 1
            max_e -= e        
            e += 1
            if max_e < 0:
                ans -=1
    print(ans)
