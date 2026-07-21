from math import *

def aaa(n):
  return int((sqrt(8*n+1)-1)/2)

def bk(n):
  if n <= 1:
    return {}
  r = {}
  for i in range(2, ceil(sqrt(n))+1):
    if n % i != 0:
      continue
    r.setdefault(i,0)
    while n % i == 0:
      n //= i
      r[i] += 1
    if n == 1:
      return r
  r.setdefault(n, 1)
  return r

n = int(input())
f = bk(n)
print(sum((aaa(m) for m in f.values())))
