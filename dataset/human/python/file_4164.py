import sys
from collections import defaultdict, Counter, deque
from itertools import accumulate, permutations, combinations
from operator import itemgetter
from bisect import bisect_left, bisect_right, bisect
from heapq import heappop, heappush
from fractions import gcd
from math import ceil, floor, sqrt, cos, sin, pi
from copy import deepcopy

# If you use recursive call, uncomment this code
#sys.setrecursionlimit(10**6)

def divider(N):
    threshold = int(sqrt(N))
    res = defaultdict(int)
    for n in range(2,threshold+1):
        while N % n == 0:
            res[n] += 1
            N //= n
    if N > 1:
        res[N] += 1
    return res

def main():
    N = int(input())
    res = divider(N)
    #print(res)
    ans = 0
    for k,v in res.items():
        i = 1
        while True:
            if v < i:
                break
            v -= i
            i += 1
            ans += 1
    print(ans)

if __name__ == '__main__':
    main()
