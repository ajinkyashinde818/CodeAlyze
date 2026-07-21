from fractions import gcd
from collections import Counter, deque, defaultdict
from heapq import heappush, heappop, heappushpop, heapify, heapreplace, merge
from bisect import bisect_left, bisect_right, bisect, insort_left, insort_right, insort
from itertools import product, combinations,permutations
from copy import deepcopy
import sys
sys.setrecursionlimit(4100000)



if __name__ == '__main__':
    N = int(input())
    A = [0]+list(map(int, input().split()))
    B = [0]+list(map(int, input().split()))
    C = [0]+list(map(int, input().split()))
    ans = 0
    prev = -1
    for i in range(1, N+1):
        dish = A[i]
        point = B[dish]
        ans += point
        if prev+1==dish:
            ans += C[prev]
        prev = dish
    print(ans)
