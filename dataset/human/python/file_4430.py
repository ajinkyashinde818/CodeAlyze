import sys
import itertools
sys.setrecursionlimit(1000000000)
from heapq import heapify,heappop,heappush,heappushpop
import math
import collections
import copy

def prime_factorize(n):
    prime_fact = []
    while n%2 == 0:
        prime_fact.append(2)
        n//=2
    f = 3
    while f * f <= n:
        if n % f == 0:
            prime_fact.append(f)
            n //= f
        else:
            f += 2
    if n != 1:
        prime_fact.append(n)
    return prime_fact

def make_divisors(n):
    divisors = []
    for i in range(1,int(n**0.5)+1):
        if n%i == 0:
            divisors.append(i)
            if i != n//i:
                divisors.append(n//i)
    divisors.sort()
    return divisors

if __name__ == "__main__":
    n = int(input())
    a = list(set(prime_factorize(n)))
    a.sort()
    cnt = 0
    for i in range(len(a)):
        e = 1
        while n%(a[i]**e) == 0:
            n = n//a[i]**e
            e += 1
            cnt+=1
    print(cnt)
