def factor(n):
    i = 2
    r = []
    while i * i <= n:
        if n % i == 0:
            c = 0
            while n % i == 0:
                c += 1
                n //= i
            r.append((i, c))
        i += 1
    if n > 1:
        r.append((n, 1))
    return r

def main():
    N = int(input())
    r = 0
    for p, e in factor(N):
        i = 1
        while e >= i:
            r += 1
            e -= i
            i += 1
    return r

print(main())
