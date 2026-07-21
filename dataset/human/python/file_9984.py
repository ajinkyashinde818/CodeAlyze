import sys
from math import ceil, floor, sqrt, sin, cos, pi
from itertools import accumulate, permutations, combinations
from fractions import gcd
from collections import deque, Counter
from operator import itemgetter
from heapq import heappop,heappush
sys.setrecursionlimit(10**7)

a, b = map(int, input().split())
print(int(a * b / gcd(a, b)))
