from math import sqrt

n = int(input())
p = n
count = 0

for i in range(2, int(sqrt(n)) + 1):
    e = 1
    while n % i ** e == 0:
        n //= i ** e
        count += 1
        e += 1
    if n % i == 0:
        while n % i == 0:
            n //= i

if n != 1:
    count += 1
if count == 0 and p != 1:
    count = 1

print(count)
