import sys
input = sys.stdin.readline
import math

import numpy as np

def INT(): return int(input())
def MAPINT(): return map(int, input().split())
def LMAPINT(): return list(map(int, input().split()))
f_inf = float('inf')

def prime_factorize(n):
    a = []
    while n % 2 == 0:
        a.append(2)
        n //= 2
    f = 3
    while f * f <= n:
        if n % f == 0:
            a.append(f)
            n //= f
        else:
            f += 2
    if n != 1:
        a.append(n)
    return a

def main():

  n = INT()
  
  if n == 1:
    print(0)
    exit()
  elif n == 2 or n == 3:
    print(1)
    exit()
  
  p = prime_factorize(n)
  setp = set(p)
  count = 0
  for s in setp:
    c = p.count(s)
    for i in range(1, c+1):
      c -= i
      if c == 0:
        count += 1
        break
      if c < 0:
        break
      count += 1
      
  print(count)

if __name__ == "__main__":
    main()
