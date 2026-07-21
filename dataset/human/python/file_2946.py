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
sosu = prime_factorize(N)
history = set()
count = 0
while len(sosu) > 0:
    num = sosu.pop(0)
    cursor = num
    while True:
        if num not in history:
            history.add(num)
            break
        if (len(sosu) <= 0):
            break
        if (cursor != sosu[0]):
            break
        num *= sosu.pop(0)

print(len(history))
