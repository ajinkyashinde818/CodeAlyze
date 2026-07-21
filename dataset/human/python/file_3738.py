import sys
from collections import Counter
from collections import deque
import heapq
import math
import fractions
import bisect
import itertools
def input(): return sys.stdin.readline().strip()
def mp(): return map(int,input().split())
def lmp(): return list(map(int,input().split()))

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
N=int(input())
dankai=[1]*50
for i in range(1,50):
    dankai[i]=dankai[i-1]+i+1

c = list(Counter(prime_factorize(N)).values())

ans=0
for v in c:
    i=0
    while v>=dankai[i]:
        i+=1
    ans+=i
print(ans)
