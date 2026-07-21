from sys import exit, setrecursionlimit, stderr
from functools import reduce
from itertools import *
from collections import defaultdict, Counter
from bisect import bisect

setrecursionlimit(10**7)

def read():
  return int(input())

def reads():
  return [int(x) for x in input().split()]

M = 10 ** 9 + 7

N = read()
S = input()

d = Counter(S)
ans = 1
for k, v in d.items():
  ans = ans * (v + 1) % M
print((ans - 1) % M)
