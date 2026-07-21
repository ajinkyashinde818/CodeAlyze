import sys
input = sys.stdin.readline
from collections import *
from fractions import *

N = int(input())

if N%2==1:
    print(0)
    exit()

two = 0

for p in range(1, 65):
    two += N//2**p

five = 0

for p in range(1, 65):
    five += N//(2*5**p)

print(min(two, five))
