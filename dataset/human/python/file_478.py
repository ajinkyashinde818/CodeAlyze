import math
import functools
import itertools
import numpy as np
import sys
MAX_INT = int(10e10)
MIN_INT = -MAX_INT
mod = 1000000007
sys.setrecursionlimit(1000000)
def IL(): return list(map(int,input().split()))
def SL(): return input().split()
def I(): return int(sys.stdin.readline())
def S(): return input()


N = I()
A = IL()

SUM = 0
cnt = 0
MIN = MAX_INT
for i in range(N):
  if A[i] < 0:
    tmp = -A[i]
    cnt += 1
  else:
    tmp = A[i]
  MIN = min(MIN,tmp)
  SUM += tmp

if cnt%2 == 0:
  print(SUM)
else:
  print(SUM-MIN*2)
