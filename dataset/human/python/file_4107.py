from math import sqrt

N = int(input())

res = 0
for i in range(2, int(sqrt(N)) + 1):
    a = set()
    b = 1
    while True:
        if N % i == 0:
            N = N // i
            b *= i
            if b not in a:
                a.add(b)
                res += 1
                b = 1
        else:
            break

if N != 1:
    res += 1

print(res)
