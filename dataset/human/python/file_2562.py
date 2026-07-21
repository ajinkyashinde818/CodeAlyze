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
import sys
read = sys.stdin.buffer.read
readline = sys.stdin.buffer.readline
readlines = sys.stdin.buffer.readlines
sys.setrecursionlimit(10**8)
INF = float('inf')
MOD = 10**9+7

def main():
  d, g = map(int, readline().split())
  pc = list(list(map(int, readline().split()))for _ in range(d))
  
  ans = INF
  
  for i in range(2**d):
    score = 0
    amari_max=0
    cnt=0
    for j in range(d):
      if (i>>j)&1:
        score += 100*(j+1)*pc[j][0] + pc[j][1]
        cnt += pc[j][0]
      else:
        amari_max = j
    for j in range(pc[amari_max][0]):
      if score>=g:
        ans = min(ans, cnt)
      score+=(amari_max + 1)*100
      cnt += 1
  print(ans)
  
  
  
  
  
if __name__ == '__main__':
  main()
