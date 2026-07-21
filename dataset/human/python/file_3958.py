import itertools
import math
import fractions
import functools
import copy
from collections import deque
from functools import reduce
from decimal import Decimal

n = int(input())

def how_many_prime(n):
    prime = {}
    num = n
    i = 2
    while True:
        if i * i > n:
            if(num > 1):
                prime[num] = 1
            break
        while num % i == 0:
            prime[i] = prime.get(i, 0) + 1
            num = num//i
        i += 1
    return prime

prime = how_many_prime(n)

count = 0
for val in prime.values():
    use = 1
    while True:
        if(val < use):
            break
        val -= use
        use += 1
        count += 1
print(count)
