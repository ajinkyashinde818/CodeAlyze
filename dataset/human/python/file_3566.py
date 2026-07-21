import math

N = int(input())

fact = set()
counter = 0

for i in range(2, int(math.sqrt(N))+1):
    if N % i != 0:
        continue
    powt = 0
    while N % i == 0:
        powt += 1
        N /= i
    fact.add((i, powt))

if N != 1:
    fact.add((N, 1))

for base, e in fact:
    for t in range(1, e+1):
        if t <= e:
            e -= t
            counter += 1
print(counter)
