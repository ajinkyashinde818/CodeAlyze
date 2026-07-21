n = int(input())

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

f = prime_factorize(n)

ans = 0
for i in set(f):
    c = f.count(i)
    j = 1
    while True:
        if 0 <= c-j:
            ans += 1
            c = c-j
            j += 1
        else:
            break

print (ans)
