import itertools
import math
import sys
from collections import Counter
from fractions import gcd
from functools import reduce

n, m = map(int, input().split())
x = []
for i in range(m):
    x.append(list(map(int, input().split())))
# print(x)
p1 = set()
p2 = set()
for i in x:
    if i[0] == 1:
       p1.add(i[1])
    elif i[1] == n:
        p2.add(i[0])
# print(p1, p2)
if len(p1 & p2) >= 1:
    print("POSSIBLE")
else:
    print("IMPOSSIBLE")
