from sys import stdin
import math
from functools import reduce

k,n = [int(x) for x in stdin.readline().rstrip().split()]

a = [int(x) for x in stdin.readline().rstrip().split()]

l = 0
for i in range(n-1):
    l = max([l, a[i+1] - a[i]])

l = max([l, a[0]+k-a[n-1]])

print(k-l)
