from math import sqrt
from math import ceil
n = int(input())
if n == 1:
    print (0)
    exit()
isP = [True] * (int(ceil(sqrt(n))))
op = 0
i = 2
n2 = n
for i in range(2, int(ceil(sqrt(n)))):
    if isP[i]:
        for j in range(2*i, int(ceil(sqrt(n))), i):
            isP[j] = False
for i in range(2, int(ceil(sqrt(n)))):
    if isP[i] and n % i == 0:
        j = i
        while n % j == 0:
            n //= j
            j *= i
            op += 1
if n > 1 and n > int(ceil(sqrt(n2))):
    op += 1

print (op)
