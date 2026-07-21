import os
import sys
from collections import defaultdict, Counter
from itertools import product, permutations,combinations, accumulate
from operator import itemgetter
from bisect import bisect_left,bisect
from heapq import heappop,heappush
from math import ceil, floor, sqrt, gcd
from copy import deepcopy

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

def retuen_num(n):
    ans = 0
    count = 0
    for i in range(2,100,1):
        count += i
        if n <= count:
            ans = i - 1
            break
        
    return ans

def main():
    n = int(input())
    sosu = prime_factorize(n)
    c = Counter(sosu)
    count = 0

    for i in c.values():
        count += retuen_num(i)

    print(count)
    

if __name__ == "__main__":
    main()
