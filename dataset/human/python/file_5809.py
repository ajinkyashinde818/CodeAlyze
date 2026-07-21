import sys
from math import ceil, floor, sqrt, sin, cos, pi
from itertools import accumulate, permutations, combinations
from fractions import gcd # 最大公約数
from collections import deque, Counter
from operator import itemgetter
from heapq import heappop,heappush
sys.setrecursionlimit(10**7)
def lcm(x, y): return ((x * y) // gcd(x, y)) # 最小公倍数
# list(map(int, input().split()))

n = int(input())
a = list(map(int, input().split()))
b = list(map(int, input().split()))
c = list(map(int, input().split()))
ans = b[a[0] - 1]
for i in range(1, len(a)):
    ans += b[a[i] - 1]
    if a[i] - a[i-1] == 1:
        ans += c[a[i-1]-1]
print(ans)
