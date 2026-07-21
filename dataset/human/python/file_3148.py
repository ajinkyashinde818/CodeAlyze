import sys
from collections import defaultdict

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

count = 0
n = int(input())
d = defaultdict(int)
ans = prime_factorize(n)
for i in ans:
    d[i] += 1
for j in d.values():
        if j < 3:
            count +=1
        elif j < 6:
            count +=2
        elif j < 10:
            count +=3
        elif j < 15:
            count +=4
        elif j < 21:
            count +=5
        elif j < 28:
            count +=6
        elif j < 36:
            count +=7
        elif j < 45:
            count +=8
        elif j < 55:
            count +=9
print(count)
