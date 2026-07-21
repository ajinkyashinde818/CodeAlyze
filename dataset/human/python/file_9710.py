import sys
import numpy as np
from math import ceil as C, floor as F, sqrt
from collections import defaultdict as D, Counter as CNT
from functools import reduce as R
 
ALP = 'ABCDEFGHIJKLMNOPQRSTUVWXYZ'
alp = 'abcdefghijklmnopqrstuvwxyz'
def _X(): return sys.stdin.readline().rstrip().split(' ')
def _S(ss): return tuple(ss) if len(ss) > 1 else ss[0]
def S(): return _S(_X())
def Ss(): return list(S())
def _I(ss): return tuple([int(s) for s in ss]) if isinstance(ss, tuple) else int(ss)
def I(): return _I(S())
def _Is(ss): return list(ss) if isinstance(ss, tuple) else [ss]
def Is(): return _Is(I())

_, k = Is()
towns = [i-1 for i in Is()]

now = 0
seen = [0]
seenx = {0: 0}

while k > 0:
  k -= 1
  now = towns[now]
  
  if now not in seenx:
    seenx[now] = len(seen)
    seen.append(now)
  else:
    seen = seen[seenx[now]:]
    break

if k == 0:
  print(1 + now)
else:
  print(1 + (seen[k % len(seen)]))
