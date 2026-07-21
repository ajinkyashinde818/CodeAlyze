from sys import exit, setrecursionlimit, stderr
from functools import reduce
from itertools import *
from collections import defaultdict, Counter
from bisect import bisect

def read():
  return int(input())

def reads():
  return [int(x) for x in input().split()]

N = read()
MAXK = int(N + 10)
ll = [k for k in range(MAXK) if k * (k - 1) == N * 2]
if len(ll) == 0:
  print('No'); exit()

K = ll[0]

S = [[] for _ in range(K)]
cnt = 1
for i in range(K):
  for j in range(i+1, K):
    S[i].append(cnt)
    S[j].append(cnt)
    cnt += 1

assert(cnt == N + 1)
print("Yes")
print(K)
for s in S:
  print(len(s), " ".join(str(c) for c in s))
