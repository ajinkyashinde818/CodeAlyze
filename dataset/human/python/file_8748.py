from sys import stdin, stdout 
from math import *
import itertools
import sys

k, n = map(int, input().split())
a = [int(i) for i in input().split()]
d = 0
for i in range(1, n):
    d = max(d, a[i] - a[i-1])

d = max(d, k - a[-1] + a[0])
print(k - d)
