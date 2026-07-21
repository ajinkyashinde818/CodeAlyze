"""
~~ Author : Bhaskar
~~ Dated : 01~06~2020
"""

import sys
from bisect import *
from math import floor,sqrt,ceil,factorial as F,gcd,pi
from itertools import chain,combinations,permutations,accumulate
from collections import Counter,defaultdict,OrderedDict,deque
from array import array
INT_MAX = sys.maxsize
INT_MIN = -(sys.maxsize)-1
mod = 1000000007
lcm = lambda a,b : (a*b)//gcd(a,b)
setbit = lambda x : bin(x)[2:].count("1")

def solve():
    n = int(sys.stdin.readline())
    d = Counter()
    while n%2 == 0:
        d[2] += 1
        n //= 2
    i = 3
    while i*i < n:
        if n%i == 0:
            while n%i == 0:
                d[i] += 1
                n //= i
        i += 2
    if n != 1:
        d[n] += 1
    ans = 0
    for k,v in d.items():
        minn = 1
        while v-minn >= 0:
            v -= minn
            minn +=1
            ans += 1
    print(ans)

if __name__ == "__main__":
    try:
        sys.stdin = open("input.txt","r")
    except :
        pass
    solve()
