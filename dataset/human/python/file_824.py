import sys, math
def input():
    return sys.stdin.readline()[:-1]
from itertools import permutations, combinations
from collections import defaultdict, Counter
from math import factorial
from bisect import bisect_left # bisect_left(list, value)
#from fractions import gcd

sys.setrecursionlimit(10**7)
N, R = map(int, input().split())

if N >= 10:
    print(R)
else:
    print(R + 100*(10-N))
