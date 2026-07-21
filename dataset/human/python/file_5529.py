import sys
import itertools
sys.setrecursionlimit(1000000000)
from heapq import heapify,heappop,heappush,heappushpop
import math
import collections

x,y = input().split()
if ord(x)>ord(y):
    print(">")
elif ord(x) == ord(y):
    print("=")
else:
    print("<")
