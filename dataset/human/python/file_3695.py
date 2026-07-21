import collections

n = int(input())


N = n
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

c = collections.Counter(a)

sosu_list = list(c.keys())

kosu_list = list(c.values())

count = 0

for index, num in enumerate(sosu_list):
    kosu = kosu_list[index]
    p = num
    e = 1
    while True:
        if kosu - e > e:
            z = p ** e
            kosu = kosu - e
            e = e + 1
            N = N / z
            count = count + 1
        else:
            count = count + 1
            break
print(count)
