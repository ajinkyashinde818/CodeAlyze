def getN():
    return int(input())
def getNM():
    return map(int, input().split())
def getList():
    return list(map(int, input().split()))
def getArray(intn):
    return [int(input()) for i in range(intn)]
def input():
    return sys.stdin.readline().rstrip()
def rand_N(ran1, ran2):
    return random.randint(ran1, ran2)
def rand_List(ran1, ran2, rantime):
    return [random.randint(ran1, ran2) for i in range(rantime)]
def rand_ints_nodup(ran1, ran2, rantime):
  ns = []
  while len(ns) < rantime:
    n = random.randint(ran1, ran2)
    if not n in ns:
      ns.append(n)
  return sorted(ns)

def rand_query(ran1, ran2, rantime):
  r_query = []
  while len(r_query) < rantime:
    n_q = rand_ints_nodup(ran1, ran2, 2)
    if not n_q in r_query:
      r_query.append(n_q)
  return sorted(r_query)

from collections import defaultdict, deque, Counter
from sys import exit
from decimal import *
import heapq
import math
from fractions import gcd
import random
import string
import copy
from itertools import combinations, permutations, product
from operator import mul, itemgetter
from functools import reduce
from bisect import bisect_left, bisect_right

import sys
sys.setrecursionlimit(1000000000)
mod = 10 ** 9 + 7

#############
# Main Code #
#############

N = input()
N = [int(i) for i in N]
# 数え上げ問題なので多分dp
dp = [[0, 0] for i in range(len(N))]

# ぴったし払うための最小値
dp[0][0] = min(N[0], 11 - N[0])
# お釣りをもらう用の紙幣を１枚余分にとっておく場合の最小値
dp[0][1] = min(N[0] + 1, 10 - N[0])

for i in range(1, len(N)):
    # dp[i - 1][1] + 10 - N[i]:とっておいた紙幣を使用し、お釣りを10 - N[i]枚もらう
    dp[i][0] = min(dp[i - 1][0] + N[i], dp[i - 1][1] + 10 - N[i])
    # dp[i - 1][1] + 9 - N[i]:お釣りを10 - N[i]枚もらい、そのうち１枚は次のお釣りを
    # もらう試行のためにとっておく
    dp[i][1] = min(dp[i - 1][0] + N[i] + 1, dp[i - 1][1] + 9 - N[i])
print(dp[len(N) - 1][0])
