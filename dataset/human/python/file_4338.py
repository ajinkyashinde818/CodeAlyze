import collections

N = int(input())

def factorize(n):
    b = 2
    fct = []
    while b * b <= n:
        while n % b == 0:
            n //= b
            fct.append(b)
        b = b + 1
    if n > 1:
        fct.append(n)
    return fct

yaku = factorize(N)
c = collections.Counter(yaku)

count = 0
for i in c.values():
    hoge = 1
    for j in range(2,10*5):
        if hoge <= i:
            hoge += j
            count += 1
        else:
            break

print(count)
