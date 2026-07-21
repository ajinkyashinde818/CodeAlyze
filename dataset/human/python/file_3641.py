import math
import sys

def make_divisors(n):
    lower_divisors , upper_divisors = [], []
    i = 1
    while i*i <= n:
        if n % i == 0:
            lower_divisors.append(i)
            if i != n // i:
                upper_divisors.append(n//i)
        i += 1
    return lower_divisors + upper_divisors[::-1]

n = int(input())

if n <= 1:
    print(0)
    sys.exit()

yakusu = set(make_divisors(n))
yakusu.discard(1)

sosu = set([min(yakusu)])
tansaku = set(yakusu)
kari = set(tansaku)



while 1:
    for var in tansaku:
        if var % max(sosu) == 0:
            kari.discard(var)
    tansaku = set(kari)
    if len(tansaku) == 0:
        break
    sosu.add(min(tansaku))
sosu = sosu | tansaku

i = 1
j = 0
kari = set(sosu)

while n != 1:
    for var in sosu:
        if n % (var ** i) == 0:
            n = n / (var ** i)
            j += 1
        else:
            kari.discard(var)
    sosu = set(kari)

    i += 1
    if i > 1000:
        break

print(j)
