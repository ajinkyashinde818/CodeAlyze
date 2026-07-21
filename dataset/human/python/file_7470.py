from scipy.sparse.csgraph import shortest_path, floyd_warshall, dijkstra, bellman_ford, johnson, minimum_spanning_tree
from scipy.sparse import csr_matrix, coo_matrix, lil_matrix
import numpy as np
from functools import reduce

from collections import deque, Counter, defaultdict
from itertools import product, permutations,combinations
from operator import itemgetter
from heapq import heappop, heappush
from bisect import bisect_left, bisect_right, bisect
from fractions import gcd
from math import ceil,floor, sqrt, cos, sin, pi, factorial
import statistics
import sys
read = sys.stdin.buffer.read
readline = sys.stdin.buffer.readline
readlines = sys.stdin.buffer.readlines
sys.setrecursionlimit(10**8)
INF = float('inf')
MOD = 10**9+7
def lcm(a, b):
  return a*b//gcd(a, b)

def main():
  S = input()
  Q = int(input())
  TFC = list(list(input().split()) for _ in range(Q))
  rev = 0
  q = deque(S)
  for i in range(Q):
    if TFC[i][0] == '1':
      rev ^= 1
    else:
      if TFC[i][1] == '1':
        if rev == 0:
          q.appendleft(TFC[i][2])
        else:
          q.append(TFC[i][2])
      else:
        if rev == 0:
          q.append(TFC[i][2])
        else:
          q.appendleft(TFC[i][2])
  ans = ''.join(q)
  print(ans if rev==0 else ans[::-1])
  
if __name__ == '__main__':
  main()
