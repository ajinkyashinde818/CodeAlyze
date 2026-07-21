from sys import exit, setrecursionlimit
from functools import reduce
from itertools import *
from collections import defaultdict
from bisect import bisect

def read():
  return int(input())

def reads():
  return [int(x) for x in input().split()]

setrecursionlimit(1000000)

(N, M) = reads()

A = []; B = []
for _ in range(N):
  s = input()
  A.append(s)
for _ in range(M):
  s = input()
  B.append(s)

for x in range(N-M+1):
  for y in range(N-M+1):
    if all(A[y+j][x:x+M] == B[j] for j in range(M)):
      print("Yes"); exit()

print("No")
