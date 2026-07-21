import sys

n = int(input())

if n == 1:
    print(0)
    sys.exit()

count = 0
i = 2

while True:
    if i * i > n:
        break

    e = 0
    while n % i == 0:
        n = n // i
        e += 1
    curr = 1
    while e >= curr:
        e -= curr
        curr += 1
        count += 1
    i += 1

if n > 1:
    print(count + 1)
else:
    print(count)
