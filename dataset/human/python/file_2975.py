import sys 
import numpy as np   
import collections 

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


readline = sys.stdin.readline 

N = int(input())

fact = prime_factorize(N)
collections_fact = collections.Counter(fact)

pre_z = 0
duplicate_num = 1
counter = 0
for z in fact:
    if z != pre_z:
        N /= z
        counter += 1
        duplicate_num = 1
    else:
        duplicate_num += 1
        duplicate_z = z**duplicate_num 
        if N % duplicate_z == 0:
            N /= duplicate_z
            counter += 1
    pre_z = z 

print(counter)
