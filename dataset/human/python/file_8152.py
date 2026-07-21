import sys
sys.setrecursionlimit(4100000)
import math
import itertools
INF = float('inf')
from heapq import heapify, heappop, heappush
import collections
import bisect

def main():
    k,s = map(int, input().split())

    ans = 0
    for x in range(k+1):
        for y in range(k+1):
            z = s - x - y
            if 0 <= z and z <= k:
                ans += 1
    print(ans)


if __name__ == '__main__':
    main()
