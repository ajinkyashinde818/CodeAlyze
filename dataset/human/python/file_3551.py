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

N = int(input())
a = prime_factorize(N)
z = set()
cnt = 0

while len(a) > 0:
    num = a.pop(0)
    cursor = num
    while True:
        if num not in z:
            z.add(num)
            break
        elif len(a) <= 0:
            break
        elif cursor != a[0]:
            break
        num *= a.pop(0)

print(len(z))
