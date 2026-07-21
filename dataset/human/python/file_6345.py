import sys, re, os
from collections import deque, defaultdict, Counter
from math import ceil, sqrt, hypot, factorial, pi, sin, cos, radians
from itertools import permutations, combinations, product, accumulate
from operator import itemgetter, mul
from copy import deepcopy
from string import ascii_lowercase, ascii_uppercase, digits
from fractions import gcd
 
def input(): return sys.stdin.readline().strip()
def INT(): return int(input())
def MAP(): return map(int, input().split())
def S_MAP(): return map(str, input().split())
def LIST(): return list(map(int, input().split()))
def S_LIST(): return list(map(str, input().split()))

sys.setrecursionlimit(10 ** 9)
INF = float('inf')
mod = 10 ** 9 + 7

def gcd(a, b):
  if a < b:
      a, b = b, a
  while a % b != 0:
      a, b = b, a % b
  return b


def lcm(a, b):
    y = a*b / gcd(a, b)
    return int(y)

def f(n):
  if n < 2:
    return 1
  elif n >= 2:
    return n * f(n - 2)


n = INT()
# print@(f(n))

# while n != 1 or n != 2:
#   n = n - 2
#   print(n)

# print(p_l)
# print(two)
# print(five)
# exit()
# a = n // 10
# print(a)
# print(124999999999999995-a)
# b = n // 2
# c = n // 5
# print(b)
# print(c)
a = 5
a_l = []

if n % 2 == 1:
  print(0)
elif n % 2 == 0: # 偶数
# if n == 0:
#   print(1)
# if 
# elif n > 1 and n <= 5:
#   print(0)

# elif n % 2 == 0:
  a = 5
  n = n // 2
  while a <= n:
    a_l.append(a)
    a = a * 5
  # print(a_l[-1])
  # print(a_l)
  ans = 0
  for a in a_l:
    ans += n // a
  
  print(ans)
# elif n % 2 == 1:
