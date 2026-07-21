N = int(input())
def prime_factorize(n):
    ans = 0
    while n % 2 == 0:
        i = 1
        j = 0
        while n % 2 == 0:
            n = n//2
            j += 1
            if i <= j:
                ans += 1
                i += 1
                j = 0
    f = 3
    while f * f <= n:
        i = 1
        j = 0
        while n % f == 0:
            n //= f
            j += 1
            if i <= j:
                ans += 1
                i += 1
                j = 0
        f += 2
    if n != 1:
        ans += 1
    return ans
print(prime_factorize(N))
