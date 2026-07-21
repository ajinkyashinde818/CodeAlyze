from sys import stdin
N = int(stdin.readline().rstrip())

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

if N == 1:
    print(0)
else:
    ans = 0
    for i,j in factorize(N):
        for k in range(1,10**9):
            j -= k
            if j < 0:
                break
            ans += 1
    print(ans)
